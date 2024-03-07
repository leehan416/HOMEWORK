def count(filename):
    try:
        # 파일 열기
        f = open(str(filename), 'r')
        data = f.read()

        # 변수 선언
        countchar = 0  # 공백 제외 문자 수
        _countchar = 0  # 공백 포함 문자 수
        countline = 0  # 줄 수
        countword = 0  # 단어 수

        # 줄 수 세기
        countline = len(data.split('\n'))

        # 단어 수 세기
        countword = len(data.strip().split())

        # 글자 수 세기
        for i in data.split('\n'):
            _countchar += len(i)
            for j in i.split():
                countchar += len(j)

        # 파일 닫기
        f.close()

        # Output.txt

        # 파일 열기
        f = open("output.txt", "w")

        # 출력
        value = "[“" + filename + "” 내용]\n" + "단어 수 : " + str(countword) + "\n" + "문자 (공백제외) : " + str(
            countchar) + "\n" + "문자 (공백포함) : " + str(
            _countchar) + "\n" + "줄 수 : " + str(countline)

        f.write(value)
        print(value)
        # 파일 닫기
        f.close()
    except IOError:  # 파일 없을 떄
        print("파일이 존재하지 않습니다.")

        
count('input.txt')
