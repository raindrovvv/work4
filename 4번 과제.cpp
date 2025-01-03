#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std 사용

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "\n" << "책이 추가되었습니다: " << title << " by " << author << endl;
		cout << " " << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\n현재 등록된 책이 없습니다." << endl;
            cout << " " << endl;
            return;
        }

        cout << "\n현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
        cout << " " << endl;
    }

	// 책 검색 메서드
    void searchBooks(const string& name) {
		bool found = false; // 책을 찾았는지 여부
		int i = 0; // 인덱스 변수
		for (const auto& book : books) { // 범위 기반 for문 사용
			if (book.title == name || book.author == name) {
				cout << "찾은 책: " << book.title << " by " << book.author << endl;
				found = true;
                cout << " " << endl;
				break;
			}
		}
		if (!found) {
			cout << "\n찾는 책이 없습니다." << endl;
		}
    }
};

int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
		cout << "3. 검색" << endl; // 검색 기능 추가
        cout << "4. 종료" << endl; // 프로그램 종료
        cout << "\n선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
		cin >> choice; // 사용자 입력을 받음

        if (cin.fail()) { // 잘못된 입력 처리, 문자를 입력했을 경우 오류 메시지를 출력하고 cin 초기화.
            	cout << "\n잘못된 입력입니다. 다시 시도하세요." << endl;
			cin.clear(); // 오류 플래그 초기화
			cin.ignore(32767, '\n'); // 잘못된 입력 제거
			continue; // 다음 반복으로 넘어감    
        }

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3번 선택: 검색
			// 책 제목으로 검색, 작가 이름으로 검색
			string name;
			cout << "검색할 책 제목 또는 작가 이름: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
			getline(cin, name); // 검색할 책 제목 또는 작가 이름 입력(공백 포함)
            manager.searchBooks(name);
        }
        else if (choice == 4) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
