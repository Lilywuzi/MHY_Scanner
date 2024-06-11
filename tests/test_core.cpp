﻿#include <gtest/gtest.h>

#include "LiveStreamLink.h"
#include "QRScanner.h"
#include "UtilString.hpp"
#include "MhyApi.hpp"

TEST(API, Test1)
{
    auto result = getStokenByGameToken("", "");
    EXPECT_TRUE(result);
}

TEST(UUID, Test1)
{
    std::string s{ createUUID4() };
    EXPECT_TRUE(s.size() > 35);
}

TEST(LiveDoyin, Test1)
{
    LiveDouyin l("85614521087");
    l.GetLiveStreamStatus();
    EXPECT_TRUE(true);
}

TEST(URLEncode, test1)
{
    HttpClient h;
    std::string s1 = "Hello%23World%22";
    std::string s3 = R"(Hello#World")";
    std::string s2 = urlDecode(s1);
    EXPECT_EQ(s2, s3);
}

TEST(LiveHuya, Test1)
{
    LiveHuya l("660000");
    l.GetLiveStreamStatus();
    EXPECT_TRUE(true);
}

TEST(LiveDouyin, Test2)
{
    EXPECT_TRUE(true);
}

TEST(LiveBili, Test1)
{
    LiveBili liveBili("6");
    EXPECT_EQ(LiveStreamStatus::Normal, liveBili.GetLiveStreamStatus());
    EXPECT_TRUE(!liveBili.GetLiveStreamLink().empty());
}

TEST(LiveBili, Test2)
{
    LiveBili liveBili("2");
    EXPECT_EQ(LiveStreamStatus::Absent, liveBili.GetLiveStreamStatus());
}

TEST(LiveBili, Test3)
{
    LiveBili liveBili("2132121");
    EXPECT_EQ(LiveStreamStatus::NotLive, liveBili.GetLiveStreamStatus());
}