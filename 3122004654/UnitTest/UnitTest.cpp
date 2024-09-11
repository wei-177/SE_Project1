#include "pch.h"
#include "CppUnitTest.h"
#include "D:/Lwcc/main.cpp"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(inputCountError1)
		{
			string expected = "Input Error!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf(); 
			cout.rdbuf(buffer.rdbuf());
			char* argv[1] = {"main.exe"};
			main(1, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(inputCountError2)
		{
			string expected = "Input Error!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[5] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_add.txt","D:/Lwcc/result.txt", "D:/Lwcc/result1.txt"};
			main(5, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(inputPathError1)
		{
			string expected = "InputPath Error!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","fdgd","trtdf","D:/Lwcc/result.txt"};
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(inputPathError2)
		{
			string expected = "InputPath Error!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","C:/Lwcc/orig.txt","E:/Lwcc/orig_0.8_add.txt","D:/Lwcc/result.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(OutputPahtNon)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_add.txt","dfguid" };//自动在main.exe路径生成文件
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(OutputPahtillegal)
		{
			string expected = "OutputPath Error!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_add.txt","$#&*%#" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}

		TEST_METHOD(TextBlank1)
		{
			string expected = "Text Blank!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/bai.txt","D:/Lwcc/result.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(TextBlank2)
		{
			string expected = "Text Blank!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/bai.txt","D:/Lwcc/bai.txt","D:/Lwcc/result.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(Right0)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig.txt","D:/Lwcc/result0.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(Right1)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_add.txt","D:/Lwcc/result1.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(Right2)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_del.txt","D:/Lwcc/result2.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(Right3)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_dis_1.txt","D:/Lwcc/result3.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(Right4)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_dis_10.txt","D:/Lwcc/result4.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
		TEST_METHOD(Right5)
		{
			string expected = "Run Successfully!\n";
			stringstream buffer;
			streambuf* sbuf = std::cout.rdbuf();
			cout.rdbuf(buffer.rdbuf());
			char* argv[4] = { "main.exe","D:/Lwcc/orig.txt","D:/Lwcc/orig_0.8_dis_15.txt","D:/Lwcc/result5.txt" };
			main(4, argv);
			cout.rdbuf(sbuf);
			Assert::AreEqual(expected, buffer.str());
		}
	};
}
