#include "Search.h"

ostream& operator<<(ostream& os, const Search& search) {
  search.print(os);
  return os;
}

H_Search::H_Search(const string& host) : host(host){ }

bool H_Search::matches(const Episode* episode) const {
    return episode->getHost() == host;
}

void H_Search::print(ostream& os) const {
    os << "Host Search: Results matching " << host << ": " << endl;
}

C_Search::C_Search(const string& cat) : category(cat) { }

bool C_Search::matches(const Episode* episode) const {
    return episode->getCategory() == category;
}

void C_Search::print(ostream& os) const {
    os << "Category Search: Results matching " << category << ": " << endl;
}

HorC_Search::HorC_Search(const string& h, const string& c) : H_Search(h), C_Search(c) { }

bool HorC_Search::matches(const  Episode* e) const {
    if (H_Search::matches(e) || C_Search::matches(e)) return true;
    return false;
}

void HorC_Search::print(ostream& os) const {
    os << "Host or Category Search: Matching with host: " << endl;
    H_Search::print(os);
    os << " or category: " << endl;
    C_Search::print(os);
}
