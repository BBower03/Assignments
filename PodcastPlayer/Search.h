#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <iostream>
#include "Episode.h"

using namespace std;

class Search {
  friend ostream& operator<<(ostream& os, const Search& search);
    public:
        virtual bool matches(const Episode*) const = 0;
        virtual void print(ostream&) const = 0;



};

class H_Search : public virtual Search {
    public:
        H_Search(const string&);
        bool matches(const Episode*) const override;
        void print(ostream&) const override;

    private:
        string host;
};

class C_Search : public virtual Search {
    public:
        C_Search(const string&);
        bool matches(const Episode*) const override;
        void print(ostream&) const override;

    private:
        string category;
};

class HorC_Search : public H_Search, public C_Search {
    public:
        HorC_Search(const string&, const string&);
        bool matches(const Episode*) const override;
        void print(ostream&) const override;
      private:
        string host;
        string category;
};



#endif
