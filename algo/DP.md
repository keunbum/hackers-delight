# Dynamic Programming

동적 계획법이란 무엇인가?

## Table Of Contants

* [개요](#개요)
* [상세](#상세)
* [다이나믹 프로그래밍의 요소](#다이나믹-프로그래밍의-요소)
* [적용](#적용)

## 개요

**동적 계획법**은 일반적으로 **최적해**(**optimal solution**)에 도달하기 위해 일련의 선택이 이루어지는 최적화 문제에 적용된다. 각각의 선택을 하는 과정에서 종종 같은 형태의 **부분 문제**가 생긴다. 동적 프로그래밍은 어떤 부분 문제가 둘 이상의 부분적인 선택 집합에서 발생하는 경우에 효과적이다. 이 기법의 중요한 특징은 부분 문제의 해가 다시 나타나는 경우를 대비해 그 해를 저장해두는 것이다. (이에 대한 구현은 크게 상향식(bottom-up)과 하향식(top-down) 접근으로 나뉘는데, 각각의 장단점은 하단에 서술한다.) 

## 상세

**dynamic programming**은 **divide and conquer** 기법처럼 부분 문제의 해를 결합해 문제를 해결한다.
(여기서 'programming'은 컴퓨터 코드를 작성한다는 의미가 아니라 '테이블'을 이용한 방법을 일컫는다.)

분할정복 알고리즘은 문제를 서로 겹치지 않는(disjoint) 부분 문제로 분할하고, 해당 부분 문제를
재귀적으로 해결한 후, 해결한 결과를 결합하여 원래의 문제를 해결한다.

반면, 동적 계획법은 부분 문제가 서로 중복될 때, 즉 어떤 부분 문제가 다시 자신의 부분 문제를 공유할 때
적용할 수 있다. 이러한 경우에도 분할정복 알고리즘을 적용한다면 공유되는 부분 문제를
반복적으로 해결하여 일을 필요 이상으로 많이 하게 된다. 동적 계획법을 이용하면 모든 부분 문제를 '한 번'만 풀어 그 해를 테이블에 저장함으로써 각 부분 문제를 풀 때마다 다시 계산하는 일을 피할 수 있다.

일반적으로 **최적화 문제**(**optimization problem**)는 다양한 해를 가질 수 있다. 대개는 이 중 최적(최소 또는 최대)의 값을 가지는 해를 찾기를 원한다. 이때 이런 해가 그 문제에 대한 유일한 최적해는 아닐 수 있다. 최적값을 가지는 해가 여러 개 존재할 수 있기 때문이다.

다이나믹 프로그래밍을 고안할 때는 대개 다음의 4단계를 거친다고 한다.

1. 해당 문제의 최적해 구조의 특징을 찾는다.
2. 최적해 값(value of optimal solution)을 재귀적으로 정의한다.
3. 최적해 값을 일반적으로 상향식(bottom-up) 방법으로 계산한다.
4. 계산된 정보(값)들로부터 통해 최적해를 구성한다.

여기서 4단계는 **최적해 자체**(ex. 배낭 문제에서 어떤 물건들을 담을 것인지 그 부분 집합)는 필요 없고 **최적해의 값**(ex. 배낭에 담긴 아이템들의 가치 합)만 필요할 경우 생략할 수 있다. 4단계를 수행할 경우, 최적해를 쉽게 구성하기 위해 3단계에서 **부가적인 정보**를 유지하기도 한다.

> 🔖 **TIP**  **최적해 구성하기**  
> 최적해를 구성하기 위해 부가적인 정보를 유지한다는 개념이 잘 와닿지 않을 수 있다. 그래프 문제에서 최적 경로를 구성하기 위해 각 노드에 대해 이전 노드를 저장하는 테크닉이 한 예이다. [숨바꼭질 4](https://www.acmicpc.net/problem/13913)로 이러한 테크닉을 연습해볼 수 있다. (이 문제는 BFS가 정해이지만 최적해를 구하는 테크닉의 예를 보여주기 위해 언급하였다.)


## 다이나믹 프로그래밍의 요소



## 적용