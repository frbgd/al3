#include <iostream>
#include <sstream>
#include <string>

// Для корректной работы freeaddrinfo в MinGW
// Подробнее: http://stackoverflow.com/a/20306451
#define _WIN32_WINNT 0x501

#include <WS2tcpip.h>
#include <WinSock2.h>

// Необходимо, чтобы линковка происходила с DLL-библиотекой
// Для работы с сокетам
#pragma comment(lib, "Ws2_32.lib")

using std::cerr;
using std::cout;

int main()
{
	WSADATA wsaData; // служебная структура для хранение информации
	// о реализации Windows Sockets
	// старт использования библиотеки сокетов процессом
	// (подгружается Ws2_32.dll)
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Если произошла ошибка подгрузки библиотеки
	if (result != 0) {
		cerr << "WSAStartup failed: " << result << "\n";
		return result;
	}

	struct addrinfo* addr = NULL; // структура, хранящая информацию
	// об IP-адресе  слущающего сокета

	// Шаблон для инициализации структуры адреса
	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));

	// IPv4 Internet protocols
	hints.ai_family = AF_INET; // AF_INET определяет, что будет
	hints.ai_socktype = SOCK_STREAM; // Задаем потоковый тип сокета
	hints.ai_protocol = IPPROTO_TCP; // Используем протокол TCP	

	// Инициализируем структуру, хранящую адрес сокета - addr
	// Наш HTTP-сервер будет висеть на 8000-м порту локалхоста
	result = getaddrinfo("127.0.0.1", "8000", &hints, &addr);

	// Если инициализация структуры адреса завершилась с ошибкой,
	// выведем сообщением об этом и завершим выполнение программы
	if (result != 0) {
		cerr << "getaddrinfo failed: " << result << "\n";
		WSACleanup(); // выгрузка библиотеки Ws2_32.dll
		return 1;
	}

	// Создание сокета
	int connect_socket = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	// Если создание сокета завершилось с ошибкой, выводим сообщение,
	// освобождаем память, выделенную под структуру addr,
	// выгружаем dll-библиотеку и закрываем программу
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
		// ошибка получения данных
		cerr << "recv failed: " << result << "\n";
		closesocket(connect_socket);
	}
	else if (result == 0) {
		// соединение закрыто клиентом
		cerr << "connection closed by server\n";
	}
	else if (result > 0) {
		cout << "data received:\n";
		for (int i = 0; i < result; i++)
			cout << buf[i];
		cout << "\n";
	}

	// Убираем за собой
	result = closesocket(connect_socket);
	if (!result) 
	{
		cout << "connection closed\n";
	}
	freeaddrinfo(addr);
	WSACleanup();
	return 0;
}
