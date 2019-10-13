#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Connector01.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class MockConnector : public Connector01
{
public:
	//MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(listen_message, void(int listeningPort));
	MOCK_METHOD2(send_message, void(int sendingPort, string message));
};

TEST(ConnectorTest, ListenMessage)
{
	//Arrange
	MockConnector conn;

	EXPECT_CALL(conn, send_message(_,_))
		.Times(1);


	//Act




	//Assert



}

//TEST(test, subtest)
//{
//	EXPECT_EQ(1, 1);
//}


//void listen_message(int listeningPort);
//void static send_message(int sendingPort, string message);