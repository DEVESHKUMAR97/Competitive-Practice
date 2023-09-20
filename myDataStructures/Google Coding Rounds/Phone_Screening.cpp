#include<bits/stdc++.h>
using namespace std;


class Browser {
public:
  stack<string> urlStackMain;
  stack<string> urlStackSecondary;
  Browser() {
    urlStackMain.push("HomeURL");
  }

  string render(string& url) {
    return "response of " + url;
  }

  string visit(string url) {
    urlStackSecondary = stack<string>();
    urlStackMain.push(url);
    return render(urlStackMain.top());
  }

  string back() {
    string topUrl = urlStackMain.top();
    urlStackMain.pop();
    urlStackSecondary.push(topUrl);
    return render(urlStackMain.top());
  }
  
  string next() {
    string topURL = urlStackSecondary.top();
    urlStackSecondary.pop();
    urlStackMain.push(topURL);
    return render(urlStackMain.top());
  }

};

int main() {
  Browser browser;
  cout << browser.visit("url1") << endl;
  cout << browser.visit("url2") << endl;
  cout << browser.visit("url3") << endl;
  cout << browser.back() << endl;
  cout << browser.back() << endl;
  cout << browser.next() << endl;
  cout << browser.next() << endl;
  cout << browser.back() << endl;
  cout << browser.back() << endl;
  cout << browser.visit("url4") << endl;
  cout << browser.back() << endl;
  cout << browser.back() << endl;
  cout << browser.next() << endl;
  cout << browser.next() << endl;
  cout << browser.next() << endl;
}





// visit, back, forward, delete



// clarifying questions
// out of box => render funciton (url) => response
// always => valid url

// ll => dp => url1 => url2 => url4 => url5
//                          => url3

// mp 
// url1 -> add(url1)
// url2 -> add(url2)
  
// #include<bits/stdc++.h>
// using namespace std;


// class Browser {
// public:
//   stack<string> urlStackMain;
//   stack<string> urlStackSecondary;
//   Browser() {
//     urlStackMain.push("HomeURL");
//   }


//   Response visit(string url) {
//     urlStackSecondary.clear();
//     urlStackMain.push(url);
//     return render(urlStackMain.top());
//   }

//   Response back() {
//     string topUrl = urlStackMain.top();
//     urlStackMain.pop();
//     urlStackSecondary.push(topURL);
//     return render(urlStackMain.top());
//   }
  
//   Response next() {
//     string topURL = urlStackSecondary.top();
//     urlStackSecondary.pop();
//     urlStackMain.push(topURL);
//     return render(urlStackMain.top());
//   }

// };
// byDefault webpage => url1

//                           => url3
                          
//                          stack1 d => url1 => url2 
                          
            
//                          stack 2 url4 => url2




// # Hello 

// # chrome => navigation

// # url =>

// # Next , prev 