# [Platinum IV] f(k, n) - 17084 

[문제 링크](https://www.acmicpc.net/problem/17084) 

### 성능 요약

메모리: 9240 KB, 시간: 336 ms

### 분류

구현, 수학

### 제출 일자

2020년 10월 29일 18:23:29

### 문제 설명

<p><em>1 </em>이상의 정수 <em>n</em>에 대하여 수열 <em>fib(n)</em>이 다음과 같이 정의되어있다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 291px; height: 46px;"></p>

<p>위 수열은 피보나치 수열로 너무 잘 알려져 있기 때문에 영훈이는 1 이상인 정수 <em>n</em>, <em>k </em>에 대한 함수 <em>f(k, n) </em>를 다음과 같이 정의했다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 306px; height: 46px;"></p>

<p>영훈이는 임의의 <em>p×p </em>행렬 <em>T</em>가 주어졌을 때, 다음 조건을 만족시키는 순서쌍 <em>(x, y)</em>의 갯수가 궁금해졌다.</p>

<ul>
	<li><em>t<sub>i-1, j-1</sub>  </em>:= 행렬 <em>T</em>의 <em>i</em>번째 행, <em>j</em>번째 열의 원소</li>
	<li><em>f(x+i, y+j) </em>=<em> t<sub>i, j</sub>      </em>(<em>for all  0 </em>≤<em>  i, j  </em><<em> p</em>)</li>
	<li>1 ≤<em>  x, y  </em>≤<em>  n - p + </em>1</li>
</ul>

<p>택희 : ..이 문제는 너무 많은 수학 지식을 요구하니까 출제하지 말자.</p>

<p>영훈 : 아냐, 잘 봐. 이게 무슨 뜻이냐면..</p>

<p>택희 : ??</p>

<p>영훈 : ??</p>

<p>택희 : 괜찮은 문제였구나..</p>

### 입력 

 <p>첫째 줄에 <em>n</em>, <em>p</em>가 주어진다. (1 ≤ <i>n</i> ≤ 10<sup>9</sup>, 1 ≤ <em>p</em> ≤ 1000)</p>

<p>둘째 줄부터 <em>p</em>개의 줄에 걸쳐 <em>p</em>개의 정수가 주어진다. 이 중 <em>i</em>번째 줄 <em>j</em>번째 정수는 <em>t<sub>i-1, j-1</sub> </em>을 의미하며, 모두 절댓값이 10<sup>18</sup> 이하인 정수이다.</p>

### 출력 

 <p>문제의 정답을 출력한다.</p>

