#include <stdio.h>
#include <stdint.h>

union Packet{
	uint32_t packet_value;
	struct{
		uint32_t crc       :2;
		uint32_t status	   :1;
		uint32_t payload   :12;
		uint32_t bat       :3;
		uint32_t sensor    :3;
		uint32_t longAddr  :8;
		uint32_t shortAddr :2;
		uint32_t addrMode  :1;
	}packetFields;
};

int main(void){
	union Packet packet;
	printf("Enter the 32 bits packet value: ");
	scanf("%X", &packet.packet_value);

	printf("crc       :%#X\n", packet.packetFields.crc);
	printf("status    :%#X\n", packet.packetFields.status);
	printf("payload   :%#X\n", packet.packetFields.payload);
	printf("bat       :%#X\n", packet.packetFields.bat);
	printf("sensor    :%#X\n", packet.packetFields.sensor);
	printf("longAddr  :%#X\n", packet.packetFields.longAddr);
	printf("shortAddr :%#X\n", packet.packetFields.shortAddr);
	printf("addrMode  :%#X\n", packet.packetFields.addrMode);

	printf("Size of union is %lu\n", sizeof(packet));

	while(getchar() != '\n');
	getchar();

}
