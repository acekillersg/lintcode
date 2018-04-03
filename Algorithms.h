//
// Created by john on 22/3/18.
//

#ifndef LINTCODE_ALGORITHMS_H
#define LINTCODE_ALGORITHMS_H

class Adder {
public:
    int add(int a, int b);
};

/**
 * add two numbers a and b without '+'
 * @param a
 * @param b
 * @return
 */
int Adder::add(int a, int b) {
    int reserve = a ^ b;
    int carry = (a & b) << 1;
    if (carry == 0)
        return reserve;
    else
        return add(carry, reserve);
}

template <typename T>
class Sorter {
public:
    void select_sorter(T array[], size_t size, bool ascending = true);
    void insert_sorter(T array[], size_t size, bool ascending = true);
    void quick_sorter(T array[], size_t size, bool ascending = true);
    void bubble_sorter(T array[], size_t size, bool ascending = true);
    int merge_sorter(T array[], size_t left, size_t right, bool ascending = true);
    int binary_search(T array[], size_t size, T element);

private:
    void quick_sorter_impl(T array[], int left, int right, bool ascending = true);
    int binary_search_impl(T array[], int left, int right, T element);
    int merge(T array[], size_t left, size_t mid, size_t right, bool ascending = true);
};

template <typename T>
void Sorter<T>::select_sorter(T *array, size_t size, bool ascending) {
    for (int i = 0; i < size; ++i) {
        T toExchange = array[i];
        size_t idx = i;
        for (int j = i; j < size; ++j) {
            if (ascending ? (array[j] < toExchange) : (array[j] > toExchange)) {
                toExchange = array[j];
                idx = j;
            }
        }
        array[idx] = array[i];
        array[i] = toExchange;
    }
}

template <typename T>
void Sorter<T>::bubble_sorter(T *array, size_t size, bool ascending) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (ascending ? (array[j] > array[j + 1]) : (array[j] < array[j + 1])) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

template <typename T>
void Sorter<T>::insert_sorter(T *array, size_t size, bool ascending) {
}

template <typename T>
void Sorter<T>::quick_sorter(T *array, size_t size, bool ascending) {
    quick_sorter_impl(array, 0, size - 1, ascending);
}

/**
 *
 * @tparam T
 * @param array
 * @param left: the index of the leftmost element
 * @param right:  the index of the rightmost element
 * @param ascending: the flag indicating ascending order or descending order
 */
template <typename T>
void Sorter<T>::quick_sorter_impl(T *array, int left, int right, bool ascending) {
    if (left < right) {
        T pivot = array[right];

        int left_idx = left;
        int right_idx = right;

        while (left_idx < right_idx) {
            while (array[left_idx] < pivot && left_idx < right_idx)
                left_idx++;

            if (left_idx < right_idx) {
                array[right_idx] = array[left_idx];
                right_idx--;
            }

            while (array[right_idx] > pivot && right_idx > left_idx)
                right_idx--;

            if (left_idx < right_idx) {
                array[left_idx] = array[right_idx];
                left_idx++;
            }
        }
        array[left_idx] = pivot;

        quick_sorter_impl(array, 0, left_idx - 1, ascending);
        quick_sorter_impl(array, left_idx + 1, right, ascending);
    }
}

template <typename T>
int Sorter<T>::merge_sorter(T *array, size_t left, size_t right, bool ascending) {
    int mid = (left + right) / 2;
    int count = 0;
    if (left < right) {
        count += merge_sorter(array, left, mid, ascending);
        count += merge_sorter(array, mid + 1, right, ascending);
        count += merge(array, left, mid, right, ascending);
    }
    return count;
}

//template <typename T>
//void Sorter<T>::divide(T *array, size_t size, T*& left, T*& right) {
//
//}

template <typename T>
int Sorter<T>::merge(T *array, size_t left, size_t mid, size_t right, bool ascending) {
    int left_idx = left;
    int right_idx = mid + 1;
    int temp_idx = 0;
    int count = 0;
    T* tempArray = new T[right - left + 1];

    while (left_idx <= mid && right_idx <= right) {
        if (array[left_idx] < array[right_idx]) {
            tempArray[temp_idx++] = array[left_idx++];
        } else {
            tempArray[temp_idx++] = array[right_idx++];
            count += (mid - left_idx + 1);
        }
    }

    while (left_idx <= mid) {
        tempArray[temp_idx++] = array[left_idx++];
    }
    while (right_idx <= right) {
        tempArray[temp_idx++] = array[right_idx++];
    }

    for (int i = 0; i < right - left + 1; ++i) {
        array[left + i] = tempArray[i];
    }
    delete tempArray;
    return count;
}

template <typename T>
int Sorter<T>::binary_search(T *array, size_t size, T element) {
    int left = 0;
    int right = size - 1;

    return binary_search_impl(array, left, right, element);
}

template <typename T>
int Sorter<T>::binary_search_impl(T *array, int left, int right, T element) {
    if (left > right)
        return -1;
    if (left == right) {
        if (array[left] == element) return left;
        else if (array[left + 1] == element) return left + 1;
        else return -1;
    }
    int mid = (left + right) / 2;
    if (element <= array[mid])
        return binary_search_impl(array, left, mid - 1, element);
    else
        return binary_search_impl(array, mid + 1, right, element);
}

void getNext(string pattern, int* next) {
//    for (int i = 0; i < pattern.length(); ++i) {
//        int max_len = 0;
//        if (i == 0) next[i] = -1;
//        else if (i == 1) next[i] = 0;
//        else {
//            int pre_post_str_len = i;
//            for (int current_len = 1; current_len <= pre_post_str_len - 1; ++current_len) {
//                int head = 0;
//                int tail = pre_post_str_len - current_len;
//
//                bool matched = true;
//                for (int k = 0; k < current_len; ++k) {
//                    if (pattern[head + k] != pattern[tail + k]) {
//                        matched = false;
//                        break;
//                    }
//                }
//            }
//        }
//    }
}

int KMP(string sentence, string pattern) {

//    int* next = new int[pattern.length()]();
//    getNext(pattern, next);
//
//    for (int i = 0; i < pattern.length(); ++i) {
//        cout << next[i] << " ";
//    }
//    delete[] next;
    return 0;
}

void maxSumInArray(int* number, int count) {
    int max = 0;
    int currentMax = 0;

    int startIdx = 0, endIdx = 0;
    for (int i = 0; i < count; ++i) {
        currentMax += number[i];

        if (currentMax > max) {
            max = currentMax;
            endIdx = i;
        }
        if (currentMax < 0) {
            currentMax = 0;
            startIdx = i + 1;
        }
    }
    cout << "Max sum of sub-sequence (" << startIdx << "," << endIdx << "): " << max << endl;
}

/**
 * Check whether current placing is legal.
 * @param col Current column to be checked.
 * @param row At current column, which row to be placed at.
 * @param board The checkerboard: index represents column, value represents at which row of this column the queen is placed.
 * @param n Number of queens.
 * @return Can or Can not place.
 */
bool check_place(int col, int board[], int n) {
    bool can_flag = true;

    // Check the same row. Note: don't need to check the same column
    for (int i = 0; i < col; ++i) {
        if (board[i] == board[col]) can_flag = false;
    }
    int c = col - 1;
    int r = board[col] - 1;
    while (c >= 0 && r >= 0) {
        if (board[c] == r) {
            can_flag = false;
            break;
        }
        else {
            c--;
            r--;
        }
    }

    int cc = col - 1;
    int rr = board[col] + 1;
    while (cc >= 0 && rr <= n - 1) {
        if (board[cc] == rr) {
            can_flag = false;
            break;
        }
        else {
            cc--;
            rr++;
        }
    }
    return can_flag;
}

void eight_queen(int n) {

    // Initialize the checkerboard
    int* board = new int[n]();
    for (int i = 0; i < n; ++i) {
        board[i] = -1;
    }

    int j = 0;
    for (; j < n; ) {
        while (board[j] < n) {
            board[j]++;
            if (board[j] == n) {
                if (j != 0) {
                    board[j] = -1;
                    j--;
                } else break;
            } else if (check_place(j, board, n)) {
                j++;
                break;
            }
        }
        if (j == 0) {
            cout << "Cannot find!" << endl;
            break;
        }
    }
    if (j == n) {
        cout << "j: " << j << endl;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (board[i] == k) cout << "*";
                else cout << "0";
            }
            cout << endl;
        }
    }
    delete[] board;
}

// Move n disks from "from" to "to" via "via"
void hanoi_impl(int n, int from, int via, int to) {
    if (n == 1) cout << "Move disk " << n - 1 << " from " << from << " to " << to << endl;
    else {
        hanoi_impl(n - 1, from, to, via);
        cout << "Move disk " << n - 1 << " from " << from << " to " << to << endl;
        hanoi_impl(n - 1, via, from, to);
    }
}

// n: the number of disks to move
void hanoi(int n) {
    hanoi_impl(n, 0, 1, 2);
}

#endif //LINTCODE_ALGORITHMS_H