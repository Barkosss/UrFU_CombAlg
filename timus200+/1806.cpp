// https://acm.timus.ru/problem.aspx?space=1&num=1806

/*
 * Каждому устройству присвоен уникальный номер — строка из десяти десятичных цифр.
 * С телеграфа A можно отправить сообщение на телеграф B только в том случае,
 * если из номера A можно получить номер B,
 * изменив в нём ровно одну цифру либо поменяв в нём две цифры местами.
 * Время передачи сообщения с телеграфа A на телеграф B зависит от длины наибольшего общего префикса их номеров — чем больше его длина,
 * тем быстрее передаётся сообщение.
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;
using std::ifstream;

unsigned long findPrefix(long fromIndexPhone, long toIndexPhone) {
    string strFromIndexPhone = std::to_string(fromIndexPhone);
    string strToIndexPhone = std::to_string(toIndexPhone);

    long len = 0;
    while (len < strFromIndexPhone.size() && len < strToIndexPhone.size() &&
           strFromIndexPhone[len] == strToIndexPhone[len]) {
        len++;
    }

    return len;
}

bool hasOnceDigit(long number) {
    cout << "===========================" << endl;
    cout << "hasOnceDigit=" << number << endl;
    bool has = false;
    long copyNumber = number;

    while (copyNumber) {
        cout << "copyNumber=" << copyNumber << " (" << has << ")" << endl;
        if (copyNumber % 10 && !has) {
            cout << "true" << " (" << has << ")" << endl;
            has = true;
        } else if (copyNumber % 10 && has) {
            cout << "false" << " (" << has << ")" << endl;
            cout << "===========================" << endl;
            return false;
        }

        copyNumber /= 10;
    }

    cout << "===========================" << endl;
    return has;
}

bool isCanGet(long fromIndexPhone, long toIndexPhone) {
    cout << "fromIndexPhone=" << fromIndexPhone << " toIndexPhone=" << toIndexPhone << endl;
    cout << "abs: " << std::abs(fromIndexPhone - toIndexPhone) << endl;
    return hasOnceDigit(std::abs(fromIndexPhone - toIndexPhone));
}

void findTransmissionPath(long countPeople, vector<long> phones, vector<long> durations) {
    long countPeopleVisited = 0, duration = 0;
    vector<long> indexes;
    indexes.push_back(1);
    long fromProne, toPhone;

    for (long indexPhone = 0; indexPhone < countPeople - 1; indexPhone++) {
        fromProne = phones[indexPhone];
        toPhone = phones[indexPhone + 1];

        if (isCanGet(fromProne, toPhone)) {
            countPeopleVisited++;
            duration += durations[findPrefix(fromProne, toPhone)];
            indexes.push_back(indexPhone);
        }
    }
    indexes.push_back(countPeople);

    cout << duration << endl << countPeopleVisited << endl;
    for (long index: indexes) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    ifstream cin("in.txt");

    long countPeople;
    cin >> countPeople;

    vector<long> durations;
    long duration;
    for (long index = 0; index < 10; index++) {
        cin >> duration;
        durations.push_back(duration);
    }

    vector<long> phones;
    long indexPhone;
    for (long index = 0; index < countPeople; index++) {
        cin >> indexPhone;
        phones.push_back(indexPhone);
    }

    findTransmissionPath(countPeople, phones, durations);

    return 0;
}