# 웹
## 웹 소개
- World Wide Web 인터넷으로 연결된 컴퓨터들이 정보를 공유하는 거대한 정보 공간
- Web
    - Web site, Web application 등을 통해 사용자들이 정보를 검색하고 상호 작용하는 기술
- Web site
    - 인터넷에서 여러 개의 Web page가 모인 것으로, 사용자들에게 정보나 서비스를 제공하는 공간
- Web page
    - HTML, CSS 등의 웹 기술을 이용하여 만들어진, **Web site**를 구성하는 하나의 요소
- Web page 구성 요소
    - HTML -> Structure
    - CSS -> Styling
    - JavaScript -> Behavior
## 웹 구조화
### HTML
- *HyperText Markup Language*
- 웹 페이지의 의미와 **구조**를 정의하는 언어
- 프로그래밍 언어는 아님
- Hypertext
    - 웹 페이지를 다른 페이지로 연결하는 링크
    - 참조를 통해 사용자가 한 문서에서 다른 문서로 즉시 접근할 수 있는 텍스트
- Markup Language
    - 태그 등을 이용하여 문서나 데이터의 구조를 명시하는 언어
    - e.g. HTML, Markdown
- html structure
    - !DOCTYPE html
        - 해당 문서가 html 문서라는 것을 나타냄
    - html /html
        - 전체 페이지의 콘텐츠 포함
    - title /title 
        - 브라우저 탭 및 즐겨찾기 시 표시되는 제목으로 사용
    - head /head 
        - html 문서에 관련된 설명, 설정 등
        - 사용자에게 보이지 않음
    - body /body 
        - 페이지에 표시되는 모든 콘텐츠
- HTML Attributes 속성</br>
    <img src="./images/html_attribute.png" width = "70%" height = "70%"></br>
    - 규칙
        - 속성은 요소 이름과 속성 사이에 공백이 있어야 함
        - 하나 이상의 속성들이 있는 경우엔 속성 사이에 공백으로 구분
        - 속성 값은 열고 닫는 따옴표로 감싸야함
    - 목적
        - 나타내고 싶진 않지만 추가적인 기능, 내용을 담고 싶을 때 사용
        - CSS에서 해당 요소를 선택하기 위한 값으로 활용됨
- HTML text structure
    - 주요 목적 중 하나는 텍스트 구조와 의미를 제공하는 것
    - 웹 페이지의 의미와 구조를 정의하는 언어
    - e.g. h1 요소는 단순히 텍스트를 크게만 만드는 것이 아닌 현재 문서의 최상위 제목이라는 의미를 부여하는 것