#include <iostream>
#include <fstream>
#include <cmath>
#include "cppjieba/Jieba.hpp"
using namespace std;

bool Read(string path, string &article) {//根据路径读取文本
    ifstream file(path);
    if (!file.is_open()) { //文件路径错误
        return false;
    }
    article = "";
    string temp;
    while (file >> temp) {
        article += temp;
    }
    file.close();
    return true;
}

double getCosineSimilarity(vector<string> &words1, vector<string>& words2) {
    
    unordered_map<string, long long> mp1, mp2;
    vector<string> check;
    for (auto temp : words1) {
        if (mp1[temp] == 0)
            check.push_back(temp);
        mp1[temp]++;
    }
    for (auto temp : words2) {
        if (mp1[temp] == 0 && mp2[temp] == 0)
            check.push_back(temp);
        mp2[temp]++;
    }
    double ans = 0, v1 = 0, v2 = 0;
    for (auto rec : check) {
        ans += mp1[rec] * mp2[rec];
        v1 += mp1[rec] * mp1[rec];
        v2 += mp2[rec] * mp2[rec];
    }
    return ans / sqrt(v1 * v2);
}

int main(int argc, char* argv[]) {
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
    jieba.extractor.Extract(article1, words1, -1);//提取文章关键词
    jieba.extractor.Extract(article2, words2, -1);
    if (words1.empty() || words2.empty()) {//判断得到的关键词数组是否为空数组，是则报错退出
        cout << "Text Blank!" << endl;
        return 0;
    }
    double cosine_similarity = getCosineSimilarity(words1, words2);//根据关键词计算余弦相似度
    ofstream file(argv[3]);
    if (!file.is_open()) {
        cout << "OutputPath Error!" << endl;
        file.close();
        return 0;
    }
    file.setf(ios::fixed);file.setf(ios::showpoint);file.precision(2);//控制精度
    file << cosine_similarity;
    file.close();
    cout << "Run Successfully!" << endl;
    return 0;
};