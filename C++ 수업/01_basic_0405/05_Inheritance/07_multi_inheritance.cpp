#include <iostream>
//두개 이상의 클래스를 상속 받은 것.
using namespace std;

class USBDevice
{
	int id;

public:
	USBDevice() = default; //기본 생성자

	USBDevice(int id) : id(id) {} //매개변수있는 생성자

	auto GetId() const { return id; }
	void PlugAndPlay() {}
};

class NetworkDevice
{
	int id;

public:
	NetworkDevice() = default; //기본 생성자

	NetworkDevice(int id) : id(id) {} //매개변수있는 생성자

	auto GetId() const { return id; }
	void Networking() {}
};

class USBNetworkDevice :public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(int usbId, int netId)
		: USBDevice(usbId), NetworkDevice(netId) //어떤 변수를 누구한테 줄지는 모르므로.
	{}

	USBNetworkDevice(int id)
		: USBDevice(id), NetworkDevice(id) //이렇게도 가능(오버로딩)
	{}
};
int main()
{
	USBNetworkDevice device(1, 2);//부모 클래스 두개 다 생김

	device.PlugAndPlay();
	device.Networking(); //부모클래스 멤버 함수 사용 가능

	device.USBDevice::GetId();
	device.NetworkDevice::GetId();
	return 0;
}