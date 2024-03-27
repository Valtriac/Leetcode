const nums = [];
let input = prompt("Enter numbers separated by commas: ");
nums.push(...input.split(",").map(Number));

let k = parseInt(prompt("Enter value for 'k': "));

var numSubarrayProductLessThanK = function(nums, k) {
  if (k <= 1) return 0;

  let left = 0, right = 0, product = 1, count = 0;
  const n = nums.length;

  while (right < n) {
    product *= nums[right];
    while (product >= k) product /= nums[left++];
    count += 1 + (right - left);
    right++;
  }

  return count;
};

console.log("Number of subarrays with product less than k:", numSubarrayProductLessThanK(nums, k));
