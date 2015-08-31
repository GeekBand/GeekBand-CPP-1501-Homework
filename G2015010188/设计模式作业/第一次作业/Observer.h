#pragma once
#include <list>
namespace geek {
	class ObserverContext {
	public:
		virtual ~ObserverContext() {}
	};

	class Observer {
	public:
		virtual void Update(ObserverContext* context) = 0;

	public:
		virtual ~Observer() {}
	};

	class Subject {
	public:
		virtual void Attach(Observer* observer) {
			observers.push_back(observer);
		}
		virtual void Detach(Observer* observer) {
			observers.remove(observer);
		}
		virtual void Notify() {
			for (auto &ob : observers) {
				ob->Update(context);
			}
		}

		void setContext(ObserverContext *c) {
			context = c;
		}
		ObserverContext* getContext() const {
			return context;
		}
	public:
		virtual ~Subject() {}
	protected:
		ObserverContext *context;
		std::list<Observer*> observers;
	};
}