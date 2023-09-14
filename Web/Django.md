# Framework
- 웹 어플리케이션을 빠르게 개발할 수 있도록 도와주는 도구
- 개발에 필요한 기본 구조, 규칙, 라이브러리 등을 제공
# Django
- Python 기반의 대표적인 웹 프레임워크
## 클라이언트와 서버
### Client
- 서비스를 요청하는 주체
- 웹 사용자의 인터넷이 연결된 장치, 웹 브라우저 등
### Server
- 클라이언트의 요청에 응답하는 주체
- 웹 페이지, 앱을 저장하는 컴퓨터
    <img src="./images/response_flowchart.png" width="70%">
## 프로젝트 및 가상환경
### 가상환경
- Python 애플리케이션과 그에 따른 패키지들을 격리하여 관리할 수 있는 **독립적인** 실행 환경
- 의존성 패키지
    - 한 소프트웨어 패키지가 다른 패키지의 기능이나 코드를 사용하기 때문에 그 패키지가 존재해야만 제대로 작동하는 관계
    - 사용하려는 패키지가 설치되지 않았거나, 호환되는 버전이 아니면 오류가 발생하거나 예상치 못한 동작을 보일 수 있음
- Django 프로젝트 생성 전 루틴
    - 가상환경 생성
    - 가상환경 활성화
    - Django 설치
    - 의존성 파일 생성
    - gitignore 생성
    - git 저장소 생성
    - Django 프로젝트 생성
### LTS *Long-Term-Support*
- 프레임워크나 라이브러리 등의 소프트웨어에서 장기간 지원되는 안정적인 버전을 의미할 때 사용
- 기업이나 대규모 프로젝트에서는 소프트웨어 업그레이드에 많은 비용과 시간이 필요하기 때문에 안정적이고 장기간 지원되는 버전이 필요
- 장고는 x.2 버전이 LTS
## 장고 프로젝트와 앱
### Django application
- 독립적으로 작동하는 기능 단위 모듈
- 각자 특정한 기능을 담당하며 다른 앱들과 함께 하나의 프로젝트를 구성
### 앱
- 앱 생성
    - 앱 이름은 '복수형'으로 지정하는 것을 권장
- 앱 등록
    - 반드시 앱을 생성한 후에 등록해야 함
    - 등록 후 생성은 불가능
## Django 디자인 패턴
### 디자인 패턴
- 소프트웨어 설계에서 발생하는 문제를 해결하기 위한 일반적인 해결책
- 공통적인 문제를 해결하는데 쓰이는 형식화 된 관행
### MVC 디자인 패턴
- Model, View, Controller
- 애플리케이션을 구조화하는 대표적인 패턴
- 데이터, 사용자 인터페이스, 비즈니스 로직을 분리
- 시각적 요소와 뒤에서 실행하는 로직을 서로 영향 없이, 독립적이고 쉽게 유지 보수를 할 수 있는 애플리케이션을 만들기 위해
### MTV 디자인 패턴
- Model, Template, View
- Django 에서 애플리케이션을 구조화하는 패턴
- 기존 MVC 패턴과 동일하나 명칭을 다르게 정의한 것
## Template System
- 데이터를 **표현**을 제어하면서, **표현**과 관련된 부분을 담당
### Django Template Language
- Template 에서 조건, 반복, 변수 등의 프로그래밍적 기능을 제공하는 시스템
- DTL Syntax
    - Variable
        - render 함수의 세번째 인자로 딕셔너리 데이터를 사용
        - 딕셔너리 key에 해당하는 문자열이 template 에서 사용 가능한 변수명이 됨
        - dot(.) 을 사용하여 변수 속성에 접근할 수 있음
    - Filters
        - 표시할 변수를 수정할 때 사용
        - chained 가 가능하여 일부 필터는 인자를 받기도 함
        - 약 60개의 built-in template filters를 제공
        - e.g. {{ name|truncatewords:30 }}
    - Tags
        - 반복 또는 논리를 수행하여 제어 흐름을 만듦
        - 일부 태그는 시작과 종료 태그가 필요
        - 약 24개의 built-in template tags를 제공
        - e.g. {% if %} {% endif %}
    - Comments
        - 주석
        - e.g. {% comment %} {% endcomment %} or {# #}
## 템플릿 상속
- 페이지의 공통요소를 포함하고, 하위 템플릿이 재정의 할 수 있는 공간을 정의하는 기본 'skeleton' 템플릿을 작성하여 상속 구조를 구축
- extends tag
    - 자식(하위) 템플릿이 부모 템플릿을 확장한다는 것을 알림
    - 반드시 템플릿 최상단에 작성되어야 함(2개 이상 사용 불가)
    - e.g. {% extends "articles/base.html" %}
- block tag
    - 하위 템플릿에서 재정의 할 수 잇는 블록을 정의
    - 하위 템플릿이 작성할 수 있는 공간을 지정
    - e.g. {% block name} {% endblock name}
## HTML form
- HTTP 요청을 서버에 보내는 가장 편리한 방법
- 'form' element
    - 사용자로부터 할당된 데이터를 서버로 전송
    - 웹에서 사용자 정보를 입력하는 여러 방식
    - text, password, checkbox 등을 제공
- 'action' & 'method'
    - action
        - 입력 데이터가 전송될 URL 을 지정
        - 만약 이 속성을 지정하지 않으면 데이터는 현재 form 이 있는 페이지의 URL로 보내짐
    - method
        - 데이터를 어떤 방식으로 보낼 것인지 정의
        - 데이터의 HTTP request methods (GET, POST)를 지정
- 'name' attribute
    - 입력한 데이터에 붙이는 이름
    - 데이터를 제출했을 때 서버는 name 속성에 설정된 값을 통해서 사용자가 입력한 데이터에 접근할 수 있음
    - Query String Parameter
        - 사용자의 입력 데이터를 URL 주소에 파라미터를 통해 서버로 보내는 방법
        - 문자열은 앰퍼샌드(&)로 연결된 key=value 쌍으로 구성되며, 기본 URL 과 물음표로 구분됨.
### HTTP request 객체
- form 으로 전송한 데이터 뿐만 아니라 모든 요청 관련 데이터가 담겨있음
- view 함수의 첫번째 인자
- e.g. requet.GET.get('message')
## Django URLs
### URL dispatcher
- URL 패턴을 정의하고 해당 패턴이 일치하는 요청을 처리할 view 함수를 연결(mapping)
### 변수와 URL
- Variable Routing
    - URL 일부터 변수를 포함시키는 것
    - 변수는 view 함수의 인자로 전달
- Variable routing 작성법
    - path_converter: variable_name
    - path converters
        - URL 변수 타입 지정
# Django Model
## Model
- Model을 통한 DB 관리
- DB의 테이블을 정의하고 데이터를 조작할 수 있는 기능들을 제공
- 테이블 구조를 설계하는 blueprint
### model 클래스 작성
- e.g.
    ```python
    # articles/models.py

    # models.Model -> 상속
    # models라는 모듈의 Model 을 상속받음
    class Article(models.Model):
        # title 은 CharField 의 인스턴스
        # Article 의 변수
        title = models.CharField(max_length=10)
        content = models.TextField()
    ```
    <img src='./images/model_class.png' width="70%">
- django.db.models 모듈의 Model 이라는 부모 클래스를 상속받음
- Model은 mode에 관련된 모든 코드가 이미 작성되어 있는 클래스
- 개발자는 가장 중요한 테이블 구조를 어떻게 설계할지에 대한 코드만 작성하도록 하기 위한 것
- 클래스 변수명
    - 테이블의 각 필드(열) 이름
- model Field 클래스
    - 테이블 필드의 **데이터 타입**
- model Field 클래스 키워드 인자(필드 옵션)
    - 테이블 필드의 **제약조건** 관련 설정
    - 제약조건
        - 데이터가 올바르게 저장되고 관리되도록 하기 위한 규칙
        - e.g. 숫자만 저장되도록, 문자가 100자까지만 저장되도록 하는 등
### Migrations
- model 클래스의 변경사항(필드 생성, 수정 삭제 등)을 DB에 최종 반영하는 방법</br>
    <img src='./images/migration_process.png' width="70%"></br>
    - 반드시 이 흐름대로 가야함
- 핵심 명령어
    ```
    $ python manage.py makemigrations
    $ python manage.py migrate
    ```
- 테이블에 필드 추가
    ```python
    # 필요한 필드 추가
    class Article(models.Model):
        title = models.CharField(max_length=10)
        content = models.TextField()
        created_at = models.DateTimeField(auto_now_add=True)
        updated_at = models.DateTimeField(auto_now=True)
    ```
    - 명령어를 입력한뒤 기본값을 작성
    - Djagno는 설계도를 쌓아가면서 추후 문제가 생겼을 시 복구하거나 되돌릴 수 있도록 함
    - model class에 변경사항이 생겼다면, 반드시 새로운 설계도를 생성해야 하고, 이를 DB에 반영 해야한다.
### model Field
- DB 테이블의 필드(열)을 정의하며, 해당 필드에 저장되는 데이터 타입과 제약조건을 정의
- CharField()
    - 길이의 제한이 있는 문자열을 넣을 때 사용
    - 필드의 최대 길이를 결정하는 max_legnth는 필수 인자
- TextField()
    - 글자의 수가 많을 때 사용
    - 각 DB 서비스 마다, 운영체제 마다 글자 수의 최대가 다르기 때문에 제한을 따로 두진 않음
- DateTimeField()
    - 날짜와 시간을 넣을 때 사용
    - ***auto_now***
        - 데이터가 저장될 때마다 자동으로 현재 날짜, 시간을 저장
        - 보통 수정일로 사용
    - ***auto_now_add***
        - 데이터가 처음 생성될 때만 자동으로 현재 날짜, 시간을 저장
        - 보통 작성일로 사용
## Admin site
### Automatic admin interface
- Django는 추가 설치 및 설정 없이 자동으로 관리자 인터페이스를 제공
- 데이터 확인 및 테스트 등을 진행하는데 매우 유용
### 참고
    ```
    $ python manage.py sqlmigrate articles 0001
    $ python manage.py showmigrations
    ```
- SQLite
    - DB 관리 시스템 중 하나이며 Django의 기본 DB로 사용
    - 파일로 존재하며 가볍고 호환성이 좋음
- CRUD
    - 소프트웨어가 가지는 기본적인 데이터 처리 기능
    - Create    저장
    - Read      조회
    - Update    갱신
    - Delete    삭제