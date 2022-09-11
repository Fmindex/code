const fm = arr => {
  let left = 0,
    right = arr.length - 1;
  if (arr.length == 1) return arr[0];
  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    if (arr[mid] <= arr[mid - 1]) {
      return arr[mid];
    } else if (arr[mid] < arr[right]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return arr[0];
};

console.log(fm([3, 4, 5, 1, 2]));
console.log(fm([2, 3, 4, 5, 1]));
console.log(fm([4, 5, 1, 2, 3]));
console.log(fm([5, 1, 2, 3, 4]));
console.log(fm([1, 2, 3, 4]));
