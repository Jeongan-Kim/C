#include <iostream>
//�ΰ� �̻��� Ŭ������ ��� ���� ��.
using namespace std;

class USBDevice
{
	int id;

public:
	USBDevice() = default; //�⺻ ������

	USBDevice(int id) : id(id) {} //�Ű������ִ� ������

	auto GetId() const { return id; }
	void PlugAndPlay() {}
};

class NetworkDevice
{
	int id;

public:
	NetworkDevice() = default; //�⺻ ������

	NetworkDevice(int id) : id(id) {} //�Ű������ִ� ������

	auto GetId() const { return id; }
	void Networking() {}
};

class USBNetworkDevice :public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(int usbId, int netId)
		: USBDevice(usbId), NetworkDevice(netId) //� ������ �������� ������ �𸣹Ƿ�.
	{}

	USBNetworkDevice(int id)
		: USBDevice(id), NetworkDevice(id) //�̷��Ե� ����(�����ε�)
	{}
};
int main()
{
	USBNetworkDevice device(1, 2);//�θ� Ŭ���� �ΰ� �� ����

	device.PlugAndPlay();
	device.Networking(); //�θ�Ŭ���� ��� �Լ� ��� ����

	device.USBDevice::GetId();
	device.NetworkDevice::GetId();
	return 0;
}