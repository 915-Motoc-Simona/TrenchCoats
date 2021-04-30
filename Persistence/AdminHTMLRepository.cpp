//
// Created by Simona on 18.04.2021.
//

#include "AdminHTMLRepository.h"
# include "regex"

AdminHTMLRepository::AdminHTMLRepository(const string &FileName) : AdminFileRepository(FileName) {

}

std::vector<TrenchCoat> AdminHTMLRepository::LoadData() {
    ifstream HTMLFile;
    HTMLFile.open(this->FileName);
    int count;

    if (HTMLFile.is_open()) {
        fstream auxFile("auxiliary.csv", ios::in | ios::out | ios::trunc);
        if (auxFile.is_open()) {
            string line;
            regex pattern("^[ /\t]*<td>.+</td>.*$");
            count = 0;
            while (HTMLFile.peek() != ifstream::traits_type::eof()) {
                getline(HTMLFile, line, '\n');
                if (regex_match(line, pattern)) {
                    int startPos = line.find("<td>");
                    int endPos = line.find("</td>");
                    string attribute = line.substr(startPos + 4, endPos - startPos - 4);
                    count++;
                    if (count != 5) {
                        auxFile << attribute << ",";
                    } else {
                        auxFile << attribute << std::endl;
                        count = 0;
                    }
                }
            }
        }
        HTMLFile.close();

        vector<TrenchCoat> entities;
        TrenchCoat T;
        auxFile.seekg(0, std::ios::beg);
        while (auxFile.peek() != std::ifstream::traits_type::eof()) {
            auxFile >> T;
            entities.push_back(T);
        }
        auxFile.close();
        return entities;
    }
}

void AdminHTMLRepository::WriteData(const vector<TrenchCoat> &Data) {
    ofstream HTMLFile;
    HTMLFile.open(this->FileName);
    string beginning = "<!DOCTYPE html>\n"
                       "<html lang=\"en\">\n"
                       "\n"
                       "<head>\n"
                       "    <meta charset=\"UTF-8\">\n"
                       "    <title>Trench coats</title>\n"
                       "</head>\n"
                       "\n"
                       "<body>\n"
                       "<table border=\"3\">\n"
                       "\n"
                       "    <tr>\n"
                       "        <th>Size</th>\n"
                       "        <th>Colour</th>\n"
                       "        <th>Price</th>\n"
                       "        <th>Quantity</th>\n"
                       "        <th>Website</th>\n"
                       "    </tr>\n";

    string final = "\n"
                   "</table>\n"
                   "</body>\n"
                   "\n"
                   "</html>";


    if (HTMLFile.is_open()) {
        HTMLFile << beginning;
        string baseAttributeLine = "\t\t<td>";
        string endAttributeLine = "</td>\n";
        for_each(Data.begin(), Data.end(), [&HTMLFile, &baseAttributeLine, &endAttributeLine](const TrenchCoat& coat) {
            string Size = baseAttributeLine + coat.GetSize() + endAttributeLine;
            string Colour = baseAttributeLine + coat.GetColour() + endAttributeLine;
            string Price = baseAttributeLine + to_string(coat.GetPrice()) + endAttributeLine;
            string Quantity = baseAttributeLine + to_string(coat.GetQuantity()) + endAttributeLine;
            string Website = baseAttributeLine + coat.GetPhotograph() + endAttributeLine;
            HTMLFile << "\t<tr>\n"
                     << Size << Colour << Price << Quantity << Website << "\t</tr>\n";
        });
        HTMLFile << final;
        HTMLFile.close();
    }
}



