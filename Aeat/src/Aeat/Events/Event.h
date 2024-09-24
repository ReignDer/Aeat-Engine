#pragma once

#include "../../aepch.h"
#include "../Core.h"

namespace Aeat {
	enum class EventType {
		None = 0,
		WindowSarado, WindowPalitLaki, WindowPokus, WindowGumalaw,
		AppKudlit, AppHimaton, AppIrender,
		KeyPinindot, KeyBinitaw,
		MousePindutanPinindot, MousePindutanBinitaw, MouseGumalaw, MouseNabalumbon
	};

	enum EventCategory {
		None= 0,
		EventCategoryApplikasyon		=BIT(0),
		EventCategoryPampasok			=BIT(1),
		EventCategoryTipaan				=BIT(2),
		EventCategoryMaws				=BIT(3),
		EventCategoryMousePindutan		=BIT(4)

	};
#define EVENT_CLASS_TYPE(type) static EventType KuninStaticType() {return EventType::type;}\
								virtual EventType KuninEventType() const override {return KuninStaticType();}\
								virtual const char* KuninName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int KuninCategoryFlags() const override {return category;}

	class AEAT_API Event { 
		friend class EventDispatcher;
	

	public:
		virtual EventType KuninEventType() const = 0;
		virtual const char* KuninName() const = 0;
		virtual int KuninCategoryFlags() const = 0;
		virtual std::string GawinString() const { return KuninName(); }

		inline bool NasaCategory(EventCategory categorya) {
			return KuninCategoryFlags() & categorya;
		}
		inline bool NaHandle() const { return m_NaHandle; }
	protected:
		bool m_NaHandle = false;
	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& pangyayari) : m_Pangyayari(pangyayari) {}
		template<typename T>
		bool Pagpapadala(EventFn<T> func) {
			if (m_Pangyayari.KuninEventType() == T::KuninStaticType()) {
				m_Pangyayari.m_NaHandle = func(*(T*)&m_Pangyayari);
				return true;
			}
			return false;
		}

	private:
		Event& m_Pangyayari;
	};

	inline std::string format_as(const Event& e) {
		return e.GawinString();
	}
}
