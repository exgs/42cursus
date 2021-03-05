## Version up
caceresenzo의 solution을 보고 이해한 뒤, 내 스타일대로 수정을 함.
---
### 내가 생각했을 때, Canceresenzo의 exam4에서 수정이 필요한 부분
1. syscall(dup2, dup, fork, pipe)에 대한 에러처리가 잘 안되어있음.
2. chdir에 대한 적용이 안되어있음.
3. 마지막에 ";" 가 들어가는 경우도 뒤에 명령어가 있다고 판단하여 `g_programs_count++;` 가 됨.
	굳이 담지 않을 데이터이고, 혼란만 야기시킨다고 생각하여, 마지막에 ";"가 들어가는 경우 `g_programs_count` 가 증가하지 않도록 함.
