#include <iostream>
#include <sstream>
#include <string>

// ��� ���������� ������ freeaddrinfo � MinGW
// ���������: http://stackoverflow.com/a/20306451
#define _WIN32_WINNT 0x501

#include <WS2tcpip.h>
#include <WinSock2.h>

// ����������, ����� �������� ����������� � DLL-�����������
// ��� ������ � �������
#pragma comment(lib, "Ws2_32.lib")

using std::cerr;
using std::cout;

int main()
{
	WSADATA wsaData; // ��������� ��������� ��� �������� ����������
	// � ���������� Windows Sockets
	// ����� ������������� ���������� ������� ���������
	// (������������ Ws2_32.dll)
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// ���� ��������� ������ ��������� ����������
	if (result != 0) {
		cerr << "WSAStartup failed: " << result << "\n";
		return result;
	}

	struct addrinfo* addr = NULL; // ���������, �������� ����������
	// �� IP-������  ���������� ������

	// ������ ��� ������������� ��������� ������
	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));

	// IPv4 Internet protocols
	hints.ai_family = AF_INET; // AF_INET ����������, ��� �����
	hints.ai_socktype = SOCK_STREAM; // ������ ��������� ��� ������
	hints.ai_protocol = IPPROTO_TCP; // ���������� �������� TCP	

	// �������������� ���������, �������� ����� ������ - addr
	// ��� HTTP-������ ����� ������ �� 8000-� ����� ����������
	result = getaddrinfo("127.0.0.1", "8000", &hints, &addr);

	// ���� ������������� ��������� ������ ����������� � �������,
	// ������� ���������� �� ���� � �������� ���������� ���������
	if (result != 0) {
		cerr << "getaddrinfo failed: " << result << "\n";
		WSACleanup(); // �������� ���������� Ws2_32.dll
		return 1;
	}

	// �������� ������
	int connect_socket = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	// ���� �������� ������ ����������� � �������, ������� ���������,
	// ����������� ������, ���������� ��� ��������� addr,
	// ��������� dll-���������� � ��������� ���������
	if (connect_socket == INVALID_SOCKET) {
		cerr << "Error at socket: " << WSAGetLastError() << "\n";
		freeaddrinfo(addr);
		WSACleanup();
		return 1;
	}

	result = connect(connect_socket, addr->ai_addr, addr->ai_addrlen);
	if (!result) {
		cout << "connection opened\n";
	}
	else
	{
		cerr << "connection failed\n";
	}

	const int max_client_buffer_size = 1024;
	char buf[max_client_buffer_size];

	std::stringstream request;
	request << "GET / HTTP/1.0\nHost: 127.0.0.1";

	result = send(connect_socket, request.str().c_str(), request.str().length(), 0);
	if (result == SOCKET_ERROR) {
		cout << "send failed: " << WSAGetLastError() << "\n";
	}
	else
	{
		cerr << "data sended\n";
	}

	result = recv(connect_socket, buf, max_client_buffer_size, 0);
	if (result == SOCKET_ERROR) {
		// ������ ��������� ������
		cerr << "recv failed: " << result << "\n";
		closesocket(connect_socket);
	}
	else if (result == 0) {
		// ���������� ������� ��������
		cerr << "connection closed by server\n";
	}
	else if (result > 0) {
		cout << "data received:\n";
		for (int i = 0; i < result; i++)
			cout << buf[i];
		cout << "\n";
	}

	// ������� �� �����
	result = closesocket(connect_socket);
	if (!result) 
	{
		cout << "connection closed\n";
	}
	freeaddrinfo(addr);
	WSACleanup();
	return 0;
}
