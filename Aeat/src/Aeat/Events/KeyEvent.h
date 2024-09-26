#pragma once

#include "Event.h"

namespace Aeat {
	class AEAT_API KeyEvent : public Event {
	public:
		inline int KuninKeyKodigo() const { return m_KeyKodigo; }
		EVENT_CLASS_CATEGORY(EventCategoryTipaan | EventCategoryPampasok)
	protected:
		KeyEvent(int keykodigo) : m_KeyKodigo(keykodigo) {}
		int m_KeyKodigo;
	};

	class AEAT_API KeyPinindotEvent : public KeyEvent {
	public:
		KeyPinindotEvent(int keykodigo, int paulitBilang) : KeyEvent(keykodigo), m_PaulitBilang(paulitBilang){}
		inline int KuninPaulitBilang() const { return m_PaulitBilang; }
		std::string GawinString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyKodigo << " (" << m_PaulitBilang << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPinindot)

	private:
		int m_PaulitBilang;
	};

	class AEAT_API KeyBinitawEvent : public KeyEvent {
	public:
		KeyBinitawEvent(int keykodigo) : KeyEvent(keykodigo) {}

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyKodigo;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPinindot)
	};
	
	class AEAT_API KeyNagTypeEvent : public KeyEvent {
	public:
		KeyNagTypeEvent(int keykodigo) : KeyEvent(keykodigo) {}

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "KeyNagTypeEvent: " << m_KeyKodigo;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyNagType)
	};

}

