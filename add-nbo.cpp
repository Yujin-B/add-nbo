#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>

	/*
	add-nbo 파일에는 각각의 파일을 저장할 file pointer를 선언하고
	파일 2개를 (.bin) 각각 받을 수 있도록 fopen, fread 함수를 호출하여
	각각 변수 2개가 그 주소를 담도록 한다. 
	읽은 데이터를 정수 변수로 저장한 후 
	이 두 변수를 합한 값을 저장하는 코드 작성
	출력 함수로 결과를 출력

	단, 출력 전 ntohl 함수를 이용하여 uint32_t 변수 2개에 들어있는 값을
        host byte로 변환해야 한다.
	*/

int main(int argc, char* argv[]){
	
	FILE* file1 = fopen(argv[1],"rb");
	FILE* file2 = fopen(argv[2],"rb");

	uint32_t data1; 
	uint32_t data2;
	fread(&data1, 1, 4,file1);
	fread(&data2, 1, 4,file2);

	data1 = ntohl(data1);
	data2 = ntohl(data2);
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", data1, data1, data2, data2, data1+data2, data1+data2);

	return 0;


}
