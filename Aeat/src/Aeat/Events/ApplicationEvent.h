#pragma once

#include "Event.h"
#include <sstream>

namespace Aeat {
	class AEAT_API WindowSaradoEvent : public Event {
		WindowSaradoEvent(){}

		EVENT_CLASS_TYPE(WindowSarado)
		EVENT_CLASS_CATEGORY(EventCategoryApplikasyon)
	};
	class AEAT_API WindowPalitLakiEvent : public Event {
	public:
		WindowPalitLakiEvent(unsigned int width, unsigned int height) : m_Laki(width), m_Haba(height){}

		inline float KuninWidth() { return m_Laki; }
		inline float KuninHaba() { return m_Haba; }

		std::string GawinString() const override {
			std::stringstream ss;
			ss << "WindowsResizeEvent: " << m_Laki << ", " << m_Haba;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(WindowPalitLaki)
		EVENT_CLASS_CATEGORY(EventCategoryApplikasyon)

	private:
		unsigned int m_Laki, m_Haba;
	};

	class AEAT_API AppKudlitEvent : public Event {
		AppKudlitEvent() {}
		EVENT_CLASS_TYPE(AppKudlit)
		EVENT_CLASS_CATEGORY(EventCategoryApplikasyon)

	};
	class AEAT_API AppHimatonEvent : public Event {
		AppHimatonEvent(){}
		EVENT_CLASS_TYPE(AppHimaton)
		EVENT_CLASS_CATEGORY(EventCategoryApplikasyon)
	};
	class AEAT_API AppIrenderEvent : public Event {
		AppIrenderEvent(){}
		EVENT_CLASS_TYPE(AppIrender)
		EVENT_CLASS_CATEGORY(EventCategoryApplikasyon)
	};

}