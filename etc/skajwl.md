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
