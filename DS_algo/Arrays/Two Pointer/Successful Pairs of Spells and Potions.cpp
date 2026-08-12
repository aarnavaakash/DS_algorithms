class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> sortedSpells;
        for (int i = 0; i< spells.size(); ++i) {
            sortedSpells.push_back({ spells[i], i });
        }

        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> answer(spells.size());
        int m = potions.size();
        int potionIndex = m - 1;

        for (const auto& [spell, index] : sortedSpells) {

            while (potionIndex >= 0 && (long long) spell * potions[potionIndex] >= success) {
                potionIndex -= 1;
            }
            answer[index] = m - (potionIndex + 1);

        }

        return answer;
    }
};
