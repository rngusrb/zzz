#include "student_predictor.hpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;
// this is simple 1-bit predictor. 
// predictor return 1(taken) when pred_arr entry set as 1.

your_own::your_own() {
    int idx_bit = 4914;
    num_predictor_entry = idx_bit;
    history = new int[num_predictor_entry] {
    };
    pred_arr00 = new int[num_predictor_entry] {
    };
    pred_arr01 = new int[num_predictor_entry] {
    };
    pred_arr10 = new int[num_predictor_entry] {
    };
    pred_arr11 = new int[num_predictor_entry] {
    };
    fill_n(pred_arr00, idx_bit, 100);
    fill_n(pred_arr01, idx_bit, 100);

    fill_n(pred_arr10, idx_bit, 100);

    fill_n(pred_arr11, idx_bit, 100);

};
your_own::~your_own() {
    if (history != NULL) delete[] history;
    if (pred_arr11 != NULL) delete[] pred_arr11;
    if (pred_arr01 != NULL) delete[] pred_arr01;

    if (pred_arr10 != NULL) delete[] pred_arr10;
    if (pred_arr00 != NULL) delete[] pred_arr00;
}
/* warning!!! Don't change argument of these function   */
int your_own::get_pred(int pc) {
    int idx = pc % num_predictor_entry;
    int prediction;
    if (history[idx] == 11) {
        if ((pred_arr11[idx] == 111) || (pred_arr11[idx] == 110) || (pred_arr11[idx] == 101) || (pred_arr11[idx] == 100)) {
            prediction = 1;
        }
        else if ((pred_arr11[idx] == 000) || (pred_arr11[idx] == 001) || (pred_arr11[idx] == 010) || (pred_arr11[idx] == 011)) {
            prediction = 0;
        }
    }
    else if (history[idx] == 10) {
        if ((pred_arr10[idx] == 111) || (pred_arr10[idx] == 110) || (pred_arr10[idx] == 101) || (pred_arr10[idx] == 100)) {
            prediction = 1;
        }
        else if ((pred_arr10[idx] == 000) || (pred_arr10[idx] == 001) || (pred_arr10[idx] == 010) || (pred_arr10[idx] == 011)) {
            prediction = 0;
        }
    }
    else if (history[idx] == 01) {
        if ((pred_arr01[idx] == 111) || (pred_arr01[idx] == 110) || (pred_arr01[idx] == 101) || (pred_arr01[idx] == 100)) {
            prediction = 1;
        }
        else if ((pred_arr01[idx] == 000) || (pred_arr01[idx] == 001) || (pred_arr01[idx] == 010) || (pred_arr01[idx] == 011)) {
            prediction = 0;
        }
    }
    else if (history[idx] == 00) {
        if ((pred_arr00[idx] == 111) || (pred_arr00[idx] == 110) || (pred_arr00[idx] == 101) || (pred_arr00[idx] == 100)) {
            prediction = 1;
        }
        else if ((pred_arr00[idx] == 000) || (pred_arr00[idx] == 001) || (pred_arr00[idx] == 010) || (pred_arr00[idx] == 011)) {
            prediction = 0;
        }
    }

    return prediction;


}


void your_own::update(int pc, int res) {

    int idx = pc % num_predictor_entry;
    int num = history[idx];
    int* arr = history;
    if (res == 1) {
        if (num == 11) {
            if (pred_arr11[idx] == 111) { pred_arr11[idx] = 111; }
            else if (pred_arr11[idx] == 110) { pred_arr11[idx] = 111; }
            else if (pred_arr11[idx] == 101) { pred_arr11[idx] = 110; }
            else if (pred_arr11[idx] == 100) { pred_arr11[idx] = 101; }
            else if (pred_arr11[idx] == 011) { pred_arr11[idx] = 100; }
            else if (pred_arr11[idx] == 010) { pred_arr11[idx] = 011; }
            else if (pred_arr11[idx] == 001) { pred_arr11[idx] = 010; }
            else if (pred_arr11[idx] == 000) { pred_arr11[idx] = 001; }
        }
        else if (num == 10) {
            if (pred_arr10[idx] == 111) { pred_arr10[idx] = 111; }
            else if (pred_arr10[idx] == 110) { pred_arr10[idx] = 111; }
            else if (pred_arr10[idx] == 101) { pred_arr10[idx] = 110; }
            else if (pred_arr10[idx] == 100) { pred_arr10[idx] = 101; }
            else if (pred_arr10[idx] == 011) { pred_arr10[idx] = 100; }
            else if (pred_arr10[idx] == 010) { pred_arr10[idx] = 011; }
            else if (pred_arr10[idx] == 001) { pred_arr10[idx] = 010; }
            else if (pred_arr10[idx] == 000) { pred_arr10[idx] = 001; }
        }
        else if (num == 01) {
            if (pred_arr01[idx] == 111) { pred_arr01[idx] = 111; }
            else if (pred_arr01[idx] == 110) { pred_arr01[idx] = 111; }
            else if (pred_arr01[idx] == 101) { pred_arr01[idx] = 110; }
            else if (pred_arr01[idx] == 100) { pred_arr01[idx] = 101; }
            else if (pred_arr01[idx] == 011) { pred_arr01[idx] = 100; }
            else if (pred_arr01[idx] == 010) { pred_arr01[idx] = 011; }
            else if (pred_arr01[idx] == 001) { pred_arr01[idx] = 010; }
            else if (pred_arr01[idx] == 000) { pred_arr01[idx] = 001; }
        }
        else if (num == 00) {
            if (pred_arr00[idx] == 111) { pred_arr00[idx] = 111; }
            else if (pred_arr00[idx] == 110) { pred_arr00[idx] = 111; }
            else if (pred_arr00[idx] == 101) { pred_arr00[idx] = 110; }
            else if (pred_arr00[idx] == 100) { pred_arr00[idx] = 101; }
            else if (pred_arr00[idx] == 011) { pred_arr00[idx] = 100; }
            else if (pred_arr00[idx] == 010) { pred_arr00[idx] = 011; }
            else if (pred_arr00[idx] == 001) { pred_arr00[idx] = 010; }
            else if (pred_arr00[idx] == 000) { pred_arr00[idx] = 001; }
        }
    }
    else if (res == 0) {
        if (num == 11) {
            if (pred_arr11[idx] == 111) { pred_arr11[idx] = 110; }
            else if (pred_arr11[idx] == 110) { pred_arr11[idx] = 101; }
            else if (pred_arr11[idx] == 101) { pred_arr11[idx] = 100; }
            else if (pred_arr11[idx] == 100) { pred_arr11[idx] = 011; }
            else if (pred_arr11[idx] == 011) { pred_arr11[idx] = 010; }
            else if (pred_arr11[idx] == 010) { pred_arr11[idx] = 001; }
            else if (pred_arr11[idx] == 001) { pred_arr11[idx] = 000; }
            else if (pred_arr11[idx] == 000) { pred_arr11[idx] = 000; }
        }
        else if (num == 10) {
            if (pred_arr10[idx] == 111) { pred_arr10[idx] = 110; }
            else if (pred_arr10[idx] == 110) { pred_arr10[idx] = 101; }
            else if (pred_arr10[idx] == 101) { pred_arr10[idx] = 100; }
            else if (pred_arr10[idx] == 100) { pred_arr10[idx] = 011; }
            else if (pred_arr10[idx] == 011) { pred_arr10[idx] = 010; }
            else if (pred_arr10[idx] == 010) { pred_arr10[idx] = 001; }
            else if (pred_arr10[idx] == 001) { pred_arr10[idx] = 000; }
            else if (pred_arr10[idx] == 000) { pred_arr10[idx] = 000; }
        }
        else if (num == 01) {
            if (pred_arr01[idx] == 111) { pred_arr01[idx] = 110; }
            else if (pred_arr01[idx] == 110) { pred_arr01[idx] = 101; }
            else if (pred_arr01[idx] == 101) { pred_arr01[idx] = 100; }
            else if (pred_arr01[idx] == 100) { pred_arr01[idx] = 011; }
            else if (pred_arr01[idx] == 011) { pred_arr01[idx] = 010; }
            else if (pred_arr01[idx] == 010) { pred_arr01[idx] = 001; }
            else if (pred_arr01[idx] == 001) { pred_arr01[idx] = 000; }
            else if (pred_arr01[idx] == 000) { pred_arr01[idx] = 000; }
        }
        else if (num == 00) {
            if (pred_arr00[idx] == 111) { pred_arr00[idx] = 110; }
            else if (pred_arr00[idx] == 110) { pred_arr00[idx] = 101; }
            else if (pred_arr00[idx] == 101) { pred_arr00[idx] = 100; }
            else if (pred_arr00[idx] == 100) { pred_arr00[idx] = 011; }
            else if (pred_arr00[idx] == 011) { pred_arr00[idx] = 010; }
            else if (pred_arr00[idx] == 010) { pred_arr00[idx] = 001; }
            else if (pred_arr00[idx] == 001) { pred_arr00[idx] = 000; }
            else if (pred_arr00[idx] == 000) { pred_arr00[idx] = 000; }
        }

    }
    if (res == 1) {
        if (arr[idx] == 11) { arr[idx] = 11; }
        else if (arr[idx] == 10) { arr[idx] = 01; }
        else if (arr[idx] == 00) { arr[idx] = 01; }
        else if (arr[idx] == 01) { arr[idx] = 11; }
    }
    else {
        if (arr[idx] == 11) { arr[idx] = 10; }
        else if (arr[idx] == 10) { arr[idx] = 00; }
        else if (arr[idx] == 00) { arr[idx] = 00; }
        else if (arr[idx] == 01) { arr[idx] = 10; }

    }
}