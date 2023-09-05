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
    - Heading & Paragraps : h1~6, p
    - Lists : ol, ul, li
    - Emphasis & Importance : em, strong
### CSS
- *Cascading Style Sheet*
- 웹 페이지의 디자인과 레이아웃을 구성하는 언어
- CSS 적용법
    - Inline 스타일 : html 요소안에 style 속성 값으로 작성
    - Internal 스타일 시트 : head 태그 안에 style 태그에 작성
    - External 스타일 시트 : 별도의 CSS 파일 생성 후 HTML link 태그를 사용해 불러오기
- CSS Selectors
    - HTML 요소를 선택하여 스타일을 적용할 수 있도록 하는 선택자
    - 기본 선택자
        - 전체(*) 선택자
        - 요소(tag) 선택자
        - class 선택자
            - 주어진 클래스 속성을 가진 모든 요소를 선택
        - id 선택자
            - 주어진 아이디 속성을 가진 요소 선택
            - 문서에는 주어진 아이디를 가진 요소가 하나만 있어야 함
        - 속성(attr) 선택자
    - 결합자 Combinators
        - 자손 결합자 (" "(space))
            - 첫 번째 요소의 자손 요소들 선택
            - e.g. p span 은 p 안에 있는 모든 span 를 선택(하위 레벨 상관 없이)
        - 자식 결합자 (>)
            - 첫 번째 요소의 직계 자식만 선택
            - e.g. ul > li 은 ul 안에 있는 모든 li를 선택(한단계 아래 자식들만)
- Specificity 우선순위
    - 동일한 요소에 적용 가능한 같은 스타일을 두 가지 이상 작성 했을 때 어떤 규칙이 적용 되는지 결정하는 것
    - Cascade 계단식
        - 동일한 우선순위를 같는 규칙이 적용될 때 CSS에서 마지막에 나오는 규칙이 적용됨
    - 우선순위
        1. Importance : !important
        2. Inline 스타일
        3. 선택자 : id 선택자 > class 선택자 > 요소 선택자
        4. 소스 코드 순서
    - 우선순위를 고려하기 어려워서, 보통 class로 만들어서 사용
    - !important
        - 다른 우선순위 규칙보다 우선하여 적용하는 키워드
        - 사용하는 것을 권하지 않음
### 권장사항
- 요소 tag 이름은 대소문자를 구분하지 않지만 소문자 사용을 권장
- 속성의 따옴표는 작은 따옴표와 큰 따옴표를 구분하지 않지만 큰 따옴표 권장
-  HTML은 프로그래밍 언어와 달리 에러를 반환하지 않기 때문에 작성시 주의
- CSS와 HTML 구조 정보가 혼합되어 작성되기 때문에 코드를 이해하기 어렵게 만듦
- CSS의 모든 속성을 외우는 것이 아님
- 속성은 되도록 class 만 사용할 것
### 궁금한거 생겼을 때
how to rander image in html ***mdn***
# CSS Layout
### CSS Box Model
- content, margin, padding, border 로 구성<br>
    <img src="./images/CSS_box.png" width="70%">
- 명칭</br>
    <img src="./images/box_content_names.png" width="70%"></br>