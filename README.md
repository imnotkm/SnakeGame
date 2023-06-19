# 프로젝트 소개

본 프로그램은 국민대학교 C++ 프로그래밍 과목의 팀 프로젝트 과제를 수행한 결과물입니다.  
2차원 평면 위의 가상의 뱀을 조종하여 도전 과제를 수행하는 게임입니다.

<h2>게임 진행</h2>

1. 게임 화면의 좌측하단에 가상의 뱀이 생성됩니다.
2. 플레이어는 키보드의 방향키를 입력하여 뱀을 움직일 수 있습니다.
3. 플레이어가 방향을 입력하지 않아도 뱀은 진행하던 방향으로 움직입니다.
4. 우측 화면에 주어진 도전 과제를 수행합니다.
5. 모든 목표를 달성하면 다음 단계로 넘어갑니다.  
6. 총 다섯 단계에 도전할 수 있으며 단계별로 난이도가 올라갑니다.  
7. 모든 단계의 목표를 달성하면 게임이 종료됩니다.

<h2>게임 실패</h2>

다음 상황에서 게임은 실패합니다.

* 뱀의 길이가 3보다 짧을 때
* 뱀이 벽에 부딪혔을 때
* 뱀이 이동하던 방향의 반대 방향이 입력되었을 때

실패한 이유와 함께 게임 종료 화면이 출력됩니다.

<h2>도전 과제</h2>

다음 조건을 만족하면 다음 단계에 도전할 수 있습니다.

* 뱀의 최대길이가 6 이상
* 통과한 관문이 환 개 이상
* 획득한 성장 아이템이 한 개 이상
* 획득한 독 아이템이 한 개 이상

<h2>맵</h2>

맵은 다음과 같이 구성됩니다.

> <h3>1. 벽</h3>
>
> 뱀이 통과할 수 없는 장애물이다  
> 뱀은 벽에 부딪히면 죽는다
>
> * __#__ (관문이 생성될 수 있는 벽)
> * __X__ (관문이 생성될 수 없는 벽)

> <h3>2. 관문</h3>
>
> 게임 중 임의의 벽 두 개가 관문으로 전환된다
> 관문은 뱀이 50칸을 이동할 때마다 위치가 변한다
> 하나의 관문으로 들어가면 다른 관문으로 순간이동한다
> 관문을 들어갈 당시 뱀의 이동 방향이 관문을 나올 때에도 유효하다면 이동 방향이 유지된다  
> 그렇지 않다면 유효한 이동 방향으로 자동으로 설정된다
> 
> * __G__

> <h3>3. 아이템</h3>
>
> 게임 중 임의의 공백 두 개 위에 아이템 생성된다  
> 뱀이 50칸을 이동할 때마다 아이템의 위치가 변한다  
>
> * __+__ (성장 아이템: 획득 시 뱀의 길이 증가)  
> * __-__ (독 아이템: 획득 시 뱀의 길이 감소)
-------------------------------------------

# 게임 설치 및 실행

터미널을 실행하여 아래 설명에 따라 명령어를 입력합니다.

<h2>게임 설치</h2>

1. 게임을 설치할 디렉토리로 이동   

```
cd addrress_of_directory
```

    ex) cd /Users/Desktop

2. 다음과 같은 명령어를 입력한다

```
git clone https://github.com/imnotkm/SnakeGame
```

<h2>게임 실행</h2>

1. 게임을 설치한 디렉토리로 이동

```
cd address_of_SnakeGame
```

    ex) cd /Users/Desktop/SnakeGame

2. 컴파일

```
make run
```

3. executable file(.exe) 실행

```
./play
```
