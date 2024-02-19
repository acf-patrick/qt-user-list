#pragma once

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>

template<typename T>
class Observable;

template<typename T>
class Observer {
	using Function = std::function<void(T)>;
	Function callback;

	Observable<T>* observable;

	bool useOnce = false;

	std::string id;

private:
	Observer() = default;

public:
	void unsubscribe() {
		observable->remove(id);
	}

	Function getCallback() const {
		return callback;
	}

	friend class Observable<T>;
};

template<typename T>
class Observable {
	using Callback = std::function<void(T)>;

	T value;
	std::uint32_t observerCount = 0;
	std::vector<Observer<T>> observers;

	void remove(const std::string& observerId) {
		auto end = std::remove_if(
			observers.begin(),
			observers.end(),
			[observerId](const Observer<T>& observer) {
				return observer.id == observerId;
			}
		);

		if (end != observers.end()) {
			observers.erase(end);
		}
	}

public:
	Observable(const T& value) : value(value) {}

	Observable() = default;

	Observable(const Observable&) = delete;

	Observer<T> subscribe(Callback callback) {
		Observer<T> observer;
		observer.callback = callback;
		observer.observable = this;
		observer.id = std::to_string(observerCount++);

		observers.push_back(observer);
		return observer;
	}

	Observer<T> subscribeOnce(Callback callback) {
		subscribe(callback);
		auto& observer = observers.back();
		observer.useOnce = true;

		return observer;
	}

	T getValue() const {
		return value;
	}

	void next(const T& value) {
		this->value = value;
		std::vector<std::string> toRemove;

		for (auto& observer : observers) {
			observer.callback(value);
			toRemove.push_back(observer.id);
		}

		for (auto& id : toRemove) {
			remove(id);
		}
	}

	void unsubscribeAll() {
		observers.clear();
	}

	friend class Observer<T>;
};