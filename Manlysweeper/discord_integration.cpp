#include "discord_integration.h"

#include <iostream>

namespace mly
{
    namespace discord
    {
        static constexpr uint64_t DISCORD_APPLICATION_ID = UINT64_C(1573763001436209273);

        std::unique_ptr<discordpp::Client> g_client = nullptr;

        bool RichPresenceIntegration::m_active = false;
        discordpp::Activity RichPresenceIntegration::m_activity = discordpp::Activity();

        void Init()
        {
            g_client = std::make_unique<discordpp::Client>();
            g_client->SetApplicationId(DISCORD_APPLICATION_ID);
        }

        void RichPresenceIntegration::SetName(std::optional<std::string> name)
        {
            RichPresenceIntegration::m_activity.SetName(name.value_or("Manly Engine"));
        }

        void RichPresenceIntegration::SetType(discordpp::ActivityTypes type)
        {
            RichPresenceIntegration::m_activity.SetType(type);
        }

        void RichPresenceIntegration::SetDetails(std::optional<std::string> details)
        {
            RichPresenceIntegration::m_activity.SetDetails(details);
        }

        void RichPresenceIntegration::SetState(std::optional<std::string> state)
        {
            RichPresenceIntegration::m_activity.SetState(state);
        }

        void RichPresenceIntegration::SetTimestamps(std::optional<discordpp::ActivityTimestamps> timestamps)
        {
            RichPresenceIntegration::m_activity.SetTimestamps(timestamps);
        }

        void RichPresenceIntegration::SetStartTimestamp(uint64_t start)
        {
            auto timestamps = RichPresenceIntegration::m_activity.Timestamps().value_or(discordpp::ActivityTimestamps());
            timestamps.SetStart(start);
            RichPresenceIntegration::m_activity.SetTimestamps(timestamps);
        }

        void RichPresenceIntegration::SetEndTimestamp(uint64_t end)
        {
            auto timestamps = RichPresenceIntegration::m_activity.Timestamps().value_or(discordpp::ActivityTimestamps());
            timestamps.SetEnd(end);
            RichPresenceIntegration::m_activity.SetTimestamps(timestamps);
        }

        void RichPresenceIntegration::Activate()
        {
            RichPresenceIntegration::m_active = true;
            Update();
        }

        void RichPresenceIntegration::Deactivate()
        {
            RichPresenceIntegration::m_active = false;
            g_client->ClearRichPresence();
        }

        void RichPresenceIntegration::Update()
        {
            if (!RichPresenceIntegration::m_active) return;
            g_client->UpdateRichPresence(RichPresenceIntegration::m_activity, [](discordpp::ClientResult result) {
                if (!result.Successful())
                {
                    std::cerr << "Failed to update Rich Presence: [" << result.ErrorCode() << "] " << result.Error() << "\n";
                }
            });
        }
    }
}
