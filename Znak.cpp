#include "Znak.h"
#include <iostream>
#include "zodiak.h"
Znak::Znak() {}
Znak::Znak(const char* n, const char* s, Zodiak z, int day, int month, int year) {
    strcpy_s(surname, s);
    strcpy_s(name, n);
    zodiak = z;
    data[0] = day;
    data[1] = month;
    data[2] = year;
}

Znak::Znak(Znak& m) {
    strcpy_s(surname, m.surname);
    strcpy_s(name, m.name);
    zodiak = m.zodiak;

    data[0] = m.data[0];
    data[1] = m.data[1];
    data[2] = m.data[2];
}
bool Znak::operator<(Znak& z)
{
    return this->zodiak < z.zodiak;
}
bool Znak::compZodiak(Znak& z, Znak& z1)
{
    return z.zodiak < z1.zodiak;
}
ostream& operator<<(ostream& os, const Znak& m) {
    os << m.surname << " " << m.name;
    switch (m.zodiak) {
    case Zodiak::Aries:os << " Aries "; break;
    case Zodiak::Aquarius:os << " Aquarius "; break;
    case Zodiak::Cancer:os << " Cancer "; break;
    case Zodiak::Capricorn:os << " Capricorn "; break;
    case Zodiak::Gemini:os << " Gemini "; break;
    case Zodiak::Leo:os << " Leo "; break;
    case Zodiak::Libra:os << " Libra "; break;
    case Zodiak::Pisces:os << " Pisces "; break;
    case Zodiak::Sagittarius:os << " Sagittarius "; break;
    case Zodiak::Scorpio:os << " Scorpio "; break;
    case Zodiak::Taurus:os << " Taurus "; break;
    case Zodiak::Virgo:os << " Virgo ";  break;
    }
    return  os << " " << m.data[0] << " " << m.data[1] << " " << m.data[2];
}
istream& operator>>(istream& is, Znak& m) {
    char zn[20];
    is >> m.surname >> m.name;
    is >> zn >> m.data[0] >> m.data[1] >> m.data[2];
    if (strcmp(zn, "Aries") == 0) m.zodiak = Zodiak::Aries;
    if (strcmp(zn, "Taurus") == 0) m.zodiak = Zodiak::Taurus;
    if (strcmp(zn, "Gemini") == 0) m.zodiak = Zodiak::Gemini;
    if (strcmp(zn, "Cancer") == 0) m.zodiak = Zodiak::Cancer;
    if (strcmp(zn, "Leo") == 0) m.zodiak = Zodiak::Leo;
    if (strcmp(zn, "Virgo") == 0) m.zodiak = Zodiak::Virgo;
    if (strcmp(zn, "Libra") == 0) m.zodiak = Zodiak::Libra;
    if (strcmp(zn, "Scorpio") == 0) m.zodiak = Zodiak::Scorpio;
    if (strcmp(zn, "Sagittarius") == 0) m.zodiak = Zodiak::Sagittarius;
    if (strcmp(zn, "Capricorn") == 0) m.zodiak = Zodiak::Capricorn;
    if (strcmp(zn, "Aquarius") == 0) m.zodiak = Zodiak::Aquarius;
    if (strcmp(zn, "Pisces") == 0) m.zodiak = Zodiak::Pisces;

    return is;
}