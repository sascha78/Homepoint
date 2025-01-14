#pragma once

#include <mqtt/MQTTConnection.h>
#include <mqtt/MQTTGroup.hpp>
#include <mqtt/MQTTSensorGroup.hpp>

#include <map>
#include <string>
#include <tuple>
#include <vector>

using WifiCredentials = std::tuple<std::string, std::string>;

namespace model
{
struct Model
{
  WifiCredentials mWifiCredentials;
  std::string mTimeZone;
  mqtt::MQTTConfig mMQTTServerConfig;
  std::vector<MQTTVariants> mMQTTGroups;
};
} // namespace model
