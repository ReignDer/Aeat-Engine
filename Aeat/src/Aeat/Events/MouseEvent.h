#pragma once

#include "Event.h"
#include <sstream>

namespace Aeat {
	class AEAT_API MouseGumalawEvent: public Event{
	public:
		MouseGumalawEvent(float x, float y) : m_MawsX(x), m_MawsY(y) {}

		inline float KuninX() { return m_MawsX; }
		inline float KuninY() { return m_MawsY; }

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MawsX << ", " << m_MawsY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseGumalaw)
		EVENT_CLASS_CATEGORY(EventCategoryMaws | EventCategoryPampasok)	

	private:
		float m_MawsX, m_MawsY;
	};
	class AEAT_API MouseNabalumbonEvent : public Event {
	public:

		MouseNabalumbonEvent(float xOffset, float yoffset) : m_xOffset(xOffset), m_yOffset(yoffset){}

		inline float KuninXOffset() const { return m_xOffset; }
		inline float KuninYOffset() const { return m_yOffset; }

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << KuninXOffset() << ", " << KuninYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseNabalumbon)
		EVENT_CLASS_CATEGORY(EventCategoryMaws,EventCategoryPampasok)
	private:
		float m_xOffset, m_yOffset;
	};

	class AEAT_API MousePindutanEvent : public Event {
	public:
		inline int KuninMousePindutan() const { return m_Pindutan; }
		EVENT_CLASS_CATEGORY(EventCategoryMousePindutan | EventCategoryPampasok)

	protected:
		MousePindutanEvent(int mousekodigo);
		int m_Pindutan;
	};

	class AEAT_API MousePindutanPinindotEvent : public MousePindutanEvent {
	public:
		MousePindutanPinindotEvent(int pindutan) : MousePindutanEvent(pindutan){}

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Pindutan;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MousePindutanPinindot)

	};
	class AEAT_API MousePindutanBinitawEvent : public MousePindutanEvent {
	public:
		MousePindutanBinitawEvent(int pindutan) : MousePindutanEvent(pindutan) {}

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Pindutan;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MousePindutanBinitaw)
	};
}