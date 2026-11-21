#pragma once

#include <cstdint>
#include <memory>
#include <optional>

#include <discordpp.h>

namespace mly
{
    namespace discord
    {
        void Init();

        class RichPresenceIntegration
        {
        public:
            static void SetName(std::optional<std::string> name);
            static void SetType(discordpp::ActivityTypes type);
            static void SetDetails(std::optional<std::string> details);
            static void SetState(std::optional<std::string> state);
            static void SetTimestamps(std::optional<discordpp::ActivityTimestamps> timestamps);
            static void SetStartTimestamp(uint64_t start);
            static void SetEndTimestamp(uint64_t end);

            static void Activate();
            static void Deactivate();

            static void Update();

        private:
            static discordpp::Activity m_activity;

            static bool m_active;

        };
    }
}
