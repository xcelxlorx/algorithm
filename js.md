### array
```
const arr = new Array(4).fill(0);
const arr2 = new Array(4).fill().map(e => Array(5).fill(1)); //2차원 배열

let arr3 = []
arr3.push(0);
```

### for
```
arr.forEach((e, i) => {
  console.log(e, i); //e: 원소, i: index
})
```

### split & join
```
const str = "hello world";
const ret = str.split(" ");
const a = ret.join('');
```

### sort
```
arr.sort((a, b) => a - b); //asc
arr.sort((a, b) => b - a); //desc
```

### filter
```
arr.filter(e => e % 2 == 0);
```

### map
```
arr.map(e => e * 2)
```

### reduce
```
arr.reduce((total, e) => total + e, 0);
```

### find
```
//함수를 만족하는 첫 번째 요소를 반환함
//못 찾으면 undefinded
arr.find((e, i, arr) => {
  return i == 2; //index 2인 요소를 찾을 때까지 반복
})
arr.find((e, i, arr) => e === 3);
arr.find((e) => e > 8);
```

### findIndex
```
//함수를 만족하는 첫 번째 요소의 인덱스를 반환함
//못 찾으면 -1
arr.findIndex((e, i, arr) => {
  return i == 2;
})
arr.findIndex((e, i, arr) => e === 3);
arr.findIndex((e) => e > 8);
```

### indexOf, lastIndexOf
```
//없으면 -1
arr.indexOf(1); //원하는 첫번째 요소의 인덱스 찾기
arr.lastIndexOf(1); //원하는 마지막 요소의 인덱스 찾기
```

### includes
```
//배열이 특정값을 포함하고 있는지 여부를 boolean으로 반환
//값을 비교할 때 내부적으로 ===를 사용함 -> 같은 객체를 가리키고 있는 지를 비교함
//primitive type을 체크하는데 좋음
arr.includes(1); //{찾으려는 값} 
arr.includes(1, 2); //{찾으려는 값, 검색 시작 index}
```

### some
```
//파라미터로 넘어간 함수를 통해 조건에 맞는 값이 있는지 여부를 boolean으로 반환
//같은 값을 가지는지를 체크함
function findNumber(e){
  //파라미터로 element, index(optional), array(optional)가 전달될 수 있음
  if(e === 2) return true;
}

arr.some(findNumber);
```

### substring: {시작 인덱스, 종료 인덱스}
```
const str = "hello world";
str.substirng(2, 5); //2~4 -> llo
str.substring(2) //llo world
```

### substr: {시작 인덱스, 길이}
```
const str = "hello world";
str.substr(2, 3); //{시작 인덱스, 길이} -> llo
str.substr(2); //{시작 인덱스} -> llo world
str.substr(-5, 3); //-1이 뒤에서 첫 번째 -> wor
```

### slice: {시작 인덱스, 종료 인덱스}
```
//새로운 배열 만들기
arr.slice(5, 10);
arr.slice(); //전체 복제
```

### splice: {시작 인덱스, 삭제할 개수, 추가할 값 ...}
```
//특정 범위를 삭제 or 새로운 값 추가 or 기존 값 대체 
arr.splice(5, 3); //인덱스 5부터 3개 삭제, 삭제된 값을 담은 배열이 반환됨, 원본 배열에는 사라짐 
arr.splice(5, 0, 1, 2, 3); //인덱스 5부터 0개 삭제, 1~3 추가
arr.splice(5, 2, 1, 2); //인덱스 5부터 2개 삭제, 1~2 추가 -> 인덱스 5부터 2개가 1~2로 대체됨
arr.splice(10); //인덱스 10이후로 삭제
arr.splice(0); //모든 원소 삭제
```

### Object.keys, values, entries
```
//Object.keys: 객체의 키 가지고 오기
//Object.values: 객체의 값 가지고 오기
//Object.entries: 객체를 배열로 가져옴

const obj = {
  name: 'a',
  genre: 'b'
};
Object.keys(obj); //name, genre
Object.values(obj); //a, b
Object.entries(obj); //[['name', 'a'], ['genre', 'b']]

const arr = ['a', 'b', 'c']
Object.keys(obj); //0, 1, 2
Object.values(obj); //a, b, c
```

### Math.round, ceil, floor, abs
```
//나눗셈할 때, js는 실수로 변환되므로 정수로 받고 싶으면 다시 변환해야 함
let c = Math.ceil(1.2); //2
c = Math.ceil(null); //0
c = Math.ceil(1.222 / 10) * 10; //지금 1.222인데 소수점 둘째 자리에서 올림하고 싶다면, 10을 곱해주고 계산한 후 다시 10을 나눠줌

let f = Math.floor(1.5); //1
let r = Math.round(1.5); //1
r = Math.round(1.005 * 100) / 100; //IEEE 754 표준 때문에 실제 결과는 100.4999999라서 1.01이 나오지 않고 1이 나옴. -> Number.EPSILON을 더해서 해결할 수 있음
r = Math.round((1.005 + Number.EPSILON) * 100) / 100;
let a = Math.abs(-5);
```
