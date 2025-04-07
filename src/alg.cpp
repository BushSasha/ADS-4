// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        ++count1;
      }
    }
  }
  return count1;
}

int countPairs2(int *arr, int len, int value) {
  int count2 = 0;
  int end = len - 1;
  while (end > 0) {
    if (arr[end] > value) {
      end--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = end; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count2++;
    }
  }
  return count2;
}

int binarySecondSearch(int *arr, int left, int right, int target) {
  int first = -1;
  int left = low, right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= target) {
      right = mid - 1;
      if (arr[mid] == target) first = mid;
    } else {
    left = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  left = first;
  right = high;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target) {
      left = mid + 1;
      if (arr[mid] == target) last = mid;
    } else {
      right = mid - 1;
    }
  }
  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  int count3 = 0;
  for (int i = 0; i < len; ++i) {
    count3 += binarySecondSearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return count3;
}
