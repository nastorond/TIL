### VSCode UI 관련
- U untracked file
- M modified file
- A added

### 나머지
- LF Line-Feed => \n
- CR Carriage-Return => \r
- CRLF Carriage-Return + Line-Feed => \r\n


### 추가자료
- [git ignore 설정 서비스](https://www.toptal.com/developers/gitignore)
- [ignore 설정의 중요성](https://matthew.kr/해킹-기록-깃헙에-구글-클라우드-api-key가-노출된지-13분만/)
- [알고리즘 공부 참고자료](https://librewiki.net/wiki/%EC%8B%9C%EB%A6%AC%EC%A6%88:%EC%88%98%ED%95%99%EC%9D%B8%EB%93%AF_%EA%B3%BC%ED%95%99%EC%95%84%EB%8B%8C_%EA%B3%B5%ED%95%99%EA%B0%99%EC%9D%80_%EC%BB%B4%ED%93%A8%ED%84%B0%EA%B3%BC%ED%95%99/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EA%B8%B0%EC%B4%88)


### 잡설
- 성능(시간이 얼마나 빠른가) => 일반화 불가능</br>
    - 외부요인과 상황에 따라 다르기 때문</br>
map의 경우 내부의 function이 어려울 경우 for문 보다 느려짐</br>
위험한 주제</br>
- loop & map & comprehension</br>
    - 일반적으로는 comprehension이 빠름(대부분의 상황)</br>
python 개발자들이 구조적으로 빠르게 짰기 때문</br>
다른 함수, 내장 함수에 따라 map이 더 빠른경우도 많았다.</br>
python version 3. 후반대 부터 for loop 성능에 비약적인 향상이 있었음</br>
이제는 극단적인 차이는 존재하지 않음</br>
가독성에나 집중해라</br>
가독성 >>>> 간결함</br>
결국 프로그래밍이란 어떻게 그 목적을 명확하게 전달하는 가
**작은 효율성에대해서는, 말하자면 97% 정도에 대해서는, 잊어버려라</br>
섣부른 최적화는 모든 악의 근원이다** -도널드 knuth art of programming의 저자</br>
**We should forget about small efficiencies, say about 97% of the time: premature optimization is the root of all evil.**   Donald Ervin Knuth


### Short Circuit Evaluation 단축평가
```python
vowels = 'aeiou'
print(('b' and 'a' ) in vowels) # True

print(('a' and 'b' ) in vowels) # False
# 'a'는 noneempty string 이니까 True 'b'역시 True 후 결과로서 'b' return 
# 그래서 최종 결과는 False

print(('b' or 'i' ) in vowels) # False

print(('i' or 'b') in vowels) # True
# 'i'는 nonempty string 이라서 True 따라서 뒤에 값의 관계없이 결정 났으므로 결과로서 'b' return
# 그래서 최종 결과는 True

spl = 'b' or 'i' # b
spl2 = 'i' or 'b' # i
spl3 = 'i' and 'b' # b
spl4 = 'b' and 'i' # i
```

### ebnf 표기법
- '[ ]' => 선택인자, 프로그래밍 언어에서 문법을 표준화 시키기 위해 사용하는 것</br>주로 공식문서에서 표기
    ```python
    s.replace(old, new[,count])
    ```