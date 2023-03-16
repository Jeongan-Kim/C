#include <stdio.h>

//입력과 출력의 흐름
//입출력을 위한 다리 역할이 필요함

//stderr : 에러날때 쓰는 헤더 파일(?)
//버퍼가 필요한 이유 : 처리 속도에 맞춰서 입출력하기 위해.
int main()
{
	char word[100];
	char word1[100];

	//scanf("%s", word); //크기 지정안해도 되는데 오류 방지해야 함
	scanf_s("%s", word, sizeof(word)); //char형을 scan할때에는 사이즈를 넣어주는 게 좋음.(사이즈 넘게는 들어오지 않게 하는 것), '배열을 할때에는 &쓰지 않음.' 배열 자체가 주소이기 때문에.
	//scan은 공백을 입력받으면 문자열이 끝났다고 생각했기 때문에 그 뒤로는 입력되지 않고 버퍼에 저장됨.
	printf("%s\n", word);

	while (getchar() != '\n'); //getchar는 한번에 하나의 공백만 지워주므로 공백이 아닐떄까지 반복해서 지워주는 것

	gets(word1); //scanf와 다르게 공백을 만나도 포함해서 입력됨. 버퍼에 입력된 걸 모두 다 입력해주는 것, c버전 함수
	printf("%s\n", word1);


	return 0;
}