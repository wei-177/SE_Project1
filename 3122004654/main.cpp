﻿#include <iostream>
#include <fstream>
#include <cmath>
#include "cppjieba/Jieba.hpp"
using namespace std;

bool Read(string path, string &article) {//根据路径读取文本
    ifstream file(path);
    article = "";
    if (!file.is_open()) {  
        return false;
    }
    string temp;
    while (file >> temp) {
        article += temp;
    }
    file.close();
    return true;
}

double getCosineSimilarity(vector<string> &words1, vector<string>& words2) {
    
    size_t topk = (words1.size() + words2.size()) / 10;//选取关键词平均数的前1/5进行词频检测
    topk = min(min(topk, words1.size()), words2.size());//避免两篇文本字数差距过大导致发生异常
    unordered_map<string, long long> mp1, mp2;
    vector<string> check;
    for (size_t i = 0; i < topk; i++) {
        if (mp1[words1[i]] == 0 && mp2[words1[i]] == 0)
            check.push_back(words1[i]);
        if (mp1[words2[i]] == 0 && mp2[words2[i]] == 0)
            check.push_back(words2[i]);
        mp1[words1[i]]++;
        mp2[words2[i]]++;
    }
    double ans = 0, v1 = 0, v2 = 0;
    for (auto rec : check) {
        ans += mp1[rec] * mp2[rec];
        v1 += mp1[rec] * mp1[rec];
        v2 += mp2[rec] * mp2[rec];
    }
    return ans / sqrt(v1 * v2);
}

int main(int argc, char* argv[]){

    if (argc != 4) {
        cout << "Input Error!" << endl;
        return 0;
    }

    string article1, article2;
    if (!Read(argv[1], article1) || !Read(argv[2], article2)) {
        cout << "InputPath Error!" << endl;
        return 0;
    }

    cppjieba::Jieba jieba("dict/jieba.dict.utf8", "dict/hmm_model.utf8", "dict/user.dict.utf8", "dict/idf.utf8", "dict/stop_words.utf8");//jieba使用dict文件夹内文件进行初始化
    vector<string> words1, words2;
    jieba.extractor.Extract(article1, words1, -1);//使用tf-idf算法提取文章所有关键词
    jieba.extractor.Extract(article2, words2, -1);
    double cosine_similarity = getCosineSimilarity(words1, words2);//根据关键词计算余弦相似度
    if (isnan(cosine_similarity)){//判断得到的余弦相似度结果是否正常，不正常说明发生了除0操作
        cout << "Text Blank!" << endl;
        return 0;
    }
    
    ofstream file(argv[3]);
    if (!file.is_open()) {
        cout << "OutputPath Error!" << endl;
        return 0;
    }
    file.setf(ios::fixed);file.setf(ios::showpoint);file.precision(2);//控制精度
    file << cosine_similarity;
    file.close();
    cout << "Run Successfully!" << endl;
    return 0;
};