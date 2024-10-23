#include "Logger.h"
#include "ServerConfig.h"

int main()
{
	// additional workload mock for debug purposes
	Config::Logging cfg; // default values: "serverlog.txt", DEBUG_LOGS, true
	Logger::Setup(cfg);
	auto thread_vector = std::vector<std::thread>();
	for (int i = 0; i < 5; i++)
	{
		thread_vector.push_back(std::thread([]()
		{
			Logger::LogDebug("Thread debug log");
			Logger::LogError("Thread error log");
			Logger::LogWarning("Thread warning log");
		}));
	}
	for (auto& t : thread_vector)
	{
		if (t.joinable())
			t.join();
	}
}
