#include <iostream>
#include <Windows.h>
#include <string>

#include "rpc_connection.h"
#include "serialization.h"

void PrintState(RpcConnection* Connection) {
    switch (Connection->state)
    {
    case RpcConnection::State::Connected:
        std::cout << "Connected" << std::endl;
        break;
    case RpcConnection::State::AwaitingResponse:
        std::cout << "AwaitingResponse" << std::endl;
        break;
    case RpcConnection::State::Disconnected:
        std::cout << "Disconnected" << std::endl;
        break;
    case RpcConnection::State::SentHandshake:
        std::cout << "SentHandshake" << std::endl;
        break;
    default:
        std::cout << "error" << std::endl;
        break;
    }
}
void PrintBuffer(char* buf, size_t lengt) {
    for (int i = 0; i < lengt / sizeof(char); i++) {
        std::cout << buf[i];
    }
    std::cout << std::endl;

}

int main(){
    RpcConnection* Connection = RpcConnection::Create("740900603294646374");

    Connection->Open();
    Sleep(600);
    Connection->Open();

    if (Connection->IsOpen()) {
        std::cout << "Connection Open" << std::endl;
    }
    else {
        std::cout << "Connection faild" << std::endl;
        return 1;
    }

    //Connection->test();
    char msg[16 * 1024];
    size_t size = JsonWriteAuthorize(msg, sizeof(msg), 123, "740900603294646374", {"rpc"});
    PrintBuffer(msg, size);
    if (Connection->Write(&msg, size)) {
        std::cout << "verzonden" << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        JsonDocument out;
        Sleep(1000);
        if (Connection->Read(out)) {
            std::cout << "uitgelezen" << std::endl;
            auto data = GetObjMember(&out, "data");
            std::cout << "event: " << GetStrMember(&out, "evt") << ", code: " << GetIntMember(data, "code") << ", message: " << GetStrMember(data, "message", "") << std::endl;
        }
        else {
            std::cout << "niet uitgelezen" << std::endl;
        }
    }

    Connection->Close();
    PrintState(Connection);
    RpcConnection::Destroy(Connection);
    return 0;
}