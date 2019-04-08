//	This file contains functions to test functions declare in FileIO.h

#include "TestHeader.h"

void test_logMessage()
{
	logMessage("Logging first message", "testinglog.txt", true);
	logMessage("These messages should be deleted", "testinglog.txt", false);
	logMessage("Previous two messages deleted", "testinglog.txt", true);
	logMessage("Another message", "testinglog.txt", false);
}

void test_changeSetting()
{
	logMessage("Changing testprefs.txt", "testinglog.txt", false);

	changeSetting("../../../testprefs.txt", "Heading 1", 1, "New 1_1");
	changeSetting("../../../testprefs.txt", "Heading 1", 2, "New 1_2");
	changeSetting("../../../testprefs.txt", "Heading 1", 3, "New 1_3");

	changeSetting("../../../testprefs.txt", "Heading 2", 1, "Now True");
	changeSetting("../../../testprefs.txt", "Heading 2", 2, "Now False");

	changeSetting("../../../testprefs.txt", "Heading 3", 1, "008");
	changeSetting("../../../testprefs.txt", "Heading 3", 2, "765.004");
	changeSetting("../../../testprefs.txt", "Heading 3", 3, "Strings Two");
	changeSetting("../../../testprefs.txt", "Heading 3", 4, " BeforeSpace");
	changeSetting("../../../testprefs.txt", "Heading 3", 5, "AfterSpace");
}

void test_getSettings()
{
	std::vector<std::string> heading1Settings;
	std::vector<std::string> heading2Settings;
	std::vector<std::string> heading3Settings;

	heading1Settings = getSettings("../../../testprefs.txt", "Heading 1");
	heading2Settings = getSettings("../../../testprefs.txt", "Heading 2");
	heading3Settings = getSettings("../../../testprefs.txt", "Heading 4");
	heading3Settings = getSettings("../../../testprefs.txt", "Heading 3");

	logMessage("1_1 " + heading1Settings.at(0), "testinglog.txt", false);
	logMessage("1_2 " + heading1Settings.at(1), "testinglog.txt", false);
	logMessage("1_3 " + heading1Settings.at(2), "testinglog.txt", false);

	logMessage("2_1 " + heading2Settings.at(0), "testinglog.txt", false);
	logMessage("2_2 " + heading2Settings.at(1), "testinglog.txt", false);

	logMessage("3_1 " + heading3Settings.at(0), "testinglog.txt", false);
	logMessage("3_2 " + heading3Settings.at(1), "testinglog.txt", false);
	logMessage("3_3 " + heading3Settings.at(2), "testinglog.txt", false);
	logMessage("3_4 " + heading3Settings.at(3), "testinglog.txt", false);
	logMessage("3_5 " + heading3Settings.at(4), "testinglog.txt", false);
}