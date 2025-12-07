#include <bits/stdc++.h>

using namespace std;

int main() {
    fstream fin;
    vector<string> all_teams = {"american_university_eagles", "bucknell_bison", "colorado_buffaloes", "campbell_fighting_camels", "columbia_lions", "drexel_dragons", "fairfield_stags", "liberty_flames", "nc_state_wolfpack", "north_carolina_central_eagles", "princeton_tigers", "rhode_island_rams", "stony_brook_seawolves", "towson_tigers", "uconn_huskies", "delaware_blue_hens", "umass_lowell_river_hawks", "alabama_crimson_tide", "alabama_state_lady_hornets", "arkansas_razorbacks", "belmont_bruins", "charleston_cougars", "charlotte_49ers", "davidson_wildcats", "elon_phoenix", "florida_gators", "florida_gulf_coast_eagles", "florida_state_seminoles", "freed_hardeman_lions", "furman_paladins", "gardner_webb_runnin_bulldogs", "georgia_lady_bulldogs", "georgia_southern_eagles", "georgia_tech_yellow_jackets", "high_point_panthers", "houston_christian_huskies", "houston_cougars", "jackson_state_lady_tigers", "jacksonville_dolphins", "jacksonville_state_gamecocks", "little_rock_trojans", "louisiana_ragin_cajuns", "louisiana_tech_lady_techsters", "lsu_tigers", "memphis_tigers", "mercer_bears", "miami_hurricanes", "middle_tennessee_blue_raiders", "ole_miss_rebels", "oral_roberts_golden_eagles", "rice_owls", "se_louisiana_lady_lions", "south_carolina_gamecocks", "south_carolina_upstate_spartans", "south_florida_bulls", "southern_miss_lady_eagles", "stephen_f_austin_ladyjacks", "stetson_hatters", "tennessee_lady_volunteers", "tennessee_tech_golden_eagles", "troy_trojans", "tulane_green_wave", "tulsa_golden_hurricane", "ucf_knights", "wofford_terriers", "akron_zips", "app_state_mountaineers", "austin_peay_governors", "ball_state_cardinals", "cleveland_state_vikings", "coker_cobras", "dayton_flyers", "depaul_blue_demons", "drake_bulldogs", "eastern_illinois_panthers", "green_bay_phoenix", "illinois_state_redbirds", "indiana_hoosiers", "iowa_hawkeyes", "iowa_state_cyclones", "iu_indianapolis_jaguars", "kansas_city_roos", "kansas_jayhawks", "kent_state_golden_flashes", "kentucky_wildcats", "louisville_cardinals", "loyola_chicago_ramblers", "marquette_golden_eagles", "marshall_thundering_herd", "michigan_state_spartans", "michigan_wolverines", "missouri_state_lady_bears", "missouri_tigers", "murray_state_racers", "northern_iowa_panthers", "northern_kentucky_norse", "northwestern_wildcats", "notre_dame_fighting_irish", "ohio_bobcats", "ohio_state_buckeyes", "purdue_boilermakers", "southern_illinois_salukis", "toledo_rockets", "unc_pembroke_braves", "virginia_tech_hokies", "western_kentucky_lady_toppers", "western_michigan_broncos", "youngstown_state_penguins", "abilene_christian_wildcats", "air_force_falcons", "arizona_wildcats", "baylor_bears", "byu_cougars", "california_baptist_lancers", "colorado_buffaloes", "colorado_state_rams", "creighton_bluejays", "gonzaga_bulldogs", "grand_canyon_lopes", "hawaii_rainbow_wahine", "idaho_state_bengals", "kansas_state_wildcats", "long_beach_state_beach", "montana_lady_griz", "montana_state_bobcats", "nebraska_cornhuskers", "nevada_wolf_pack", "new_mexico_lobos", "north_texas_mean_green", "northern_arizona_lumberjacks", "oklahoma_sooners", "oregon_ducks", "portland_pilots", "san_diego_toreros", "san_francisco_dons", "santa_clara_broncos", "south_dakota_coyotes", "south_dakota_state_jackrabbits", "southern_utah_thunderbirds", "stanford_cardinal", "tarleton_state_texans", "texas_am_corpus_christi_islanders", "texas_am_international_dustdevils", "texas_longhorns", "texas_state_bobcats", "uc_davis_aggies", "uc_irvine_anteaters", "uc_riverside_highlanders", "uc_santa_barbara_gauchos", "ucla_bruins", "unlv_lady_rebels", "ut_arlington_mavericks", "utah_utes", "utah_valley_wolverines", "washington_state_cougars", "wyoming_cowgirls", "alabama_crimson_tide", "alabama_state_lady_hornets", "arkansas_razorbacks", "belmont_bruins", "charleston_cougars", "charlotte_49ers", "davidson_wildcats", "elon_phoenix", "florida_gators", "florida_gulf_coast_eagles", "florida_state_seminoles", "freed_hardeman_lions", "furman_paladins", "gardner_webb_runnin_bulldogs", "georgia_lady_bulldogs", "georgia_southern_eagles", "georgia_tech_yellow_jackets", "high_point_panthers", "houston_christian_huskies", "houston_cougars", "jackson_state_lady_tigers", "jacksonville_dolphins", "jacksonville_state_gamecocks", "little_rock_trojans", "louisiana_ragin_cajuns", "louisiana_tech_lady_techsters", "lsu_tigers", "memphis_tigers", "mercer_bears", "miami_hurricanes", "middle_tennessee_blue_raiders", "ole_miss_rebels", "oral_roberts_golden_eagles", "rice_owls", "se_louisiana_lady_lions", "south_carolina_gamecocks", "south_carolina_upstate_spartans", "south_florida_bulls", "southern_miss_lady_eagles", "stephen_f_austin_ladyjacks", "stetson_hatters", "tennessee_lady_volunteers", "tennessee_tech_golden_eagles", "troy_trojans", "tulane_green_wave", "tulsa_golden_hurricane", "ucf_knights", "wofford_terriers", "akron_zips", "app_state_mountaineers", "austin_peay_governors", "ball_state_cardinals", "cleveland_state_vikings", "dayton_flyers", "depaul_blue_demons", "drake_bulldogs", "eastern_illinois_panthers", "green_bay_phoenix", "illinois_state_redbirds", "indiana_hoosiers", "iowa_hawkeyes", "iowa_state_cyclones", "iu_indianapolis_jaguars", "kansas_city_roos", "kansas_jayhawks", "kent_state_golden_flashes", "kentucky_wildcats", "louisville_cardinals", "loyola_chicago_ramblers", "marquette_golden_eagles", "marshall_thundering_herd", "michigan_state_spartans", "michigan_wolverines", "missouri_state_lady_bears", "missouri_tigers", "murray_state_racers", "northern_iowa_panthers", "northern_kentucky_norse", "northwestern_wildcats", "notre_dame_fighting_irish", "ohio_bobcats", "ohio_state_buckeyes", "purdue_boilermakers", "southern_illinois_salukis", "toledo_rockets", "unc_pembroke_braves", "virginia_tech_hokies", "western_kentucky_lady_toppers", "western_michigan_broncos", "youngstown_state_penguins", "abilene_christian_wildcats", "air_force_falcons", "arizona_wildcats", "baylor_bears", "byu_cougars", "california_baptist_lancers", "colorado_buffaloes", "colorado_state_rams", "creighton_bluejays", "gonzaga_bulldogs", "grand_canyon_lopes", "hawaii_rainbow_wahine", "idaho_state_bengals", "kansas_state_wildcats", "long_beach_state_beach", "montana_lady_griz", "montana_state_bobcats", "nebraska_cornhuskers", "nevada_wolf_pack", "new_mexico_lobos", "north_texas_mean_green", "northern_arizona_lumberjacks", "oklahoma_sooners", "oregon_ducks", "portland_pilots", "san_diego_toreros", "san_francisco_dons", "santa_clara_broncos", "south_dakota_coyotes", "south_dakota_state_jackrabbits", "southern_utah_thunderbirds", "stanford_cardinal", "tarleton_state_texans", "texas_am_corpus_christi_islanders", "texas_am_international_dustdevils", "texas_longhorns", "texas_state_bobcats", "uc_davis_aggies", "uc_irvine_anteaters", "uc_riverside_highlanders", "uc_santa_barbara_gauchos", "ucla_bruins", "unlv_lady_rebels", "ut_arlington_mavericks", "utah_utes", "utah_valley_wolverines", "washington_state_cougars", "wyoming_cowgirls"};

    sort(all_teams.begin(), all_teams.end());

    auto it = unique(all_teams.begin(), all_teams.end());

    all_teams.erase(it, all_teams.end());
    all_teams.push_back("massachusetts_minutewomen");
    all_teams.push_back("north_carolina_tar_heels");
    all_teams.push_back("buffalo_bulls");
    int num_teams = all_teams.size();
    vector<float> all_scores(num_teams, 1500);

    int num_games = 5218;
    // HERE, CHANGE THE NUMBERS FOR K AND C
    int k = 26;
    float c = 0.00333333333;
    // float c = 0.33333333333;
// # USE k = 20 and c = 1/3

    // for (int b = 0; b < num_teams; b++) {
    //     cout << all_teams[b] << '\n';
    // }
    fin.open("upenn competition - Sheet66.csv", ios::in);

    for (int a = 0; a < num_games; a++) {
        string line1, team_1, team_1_score_string, team_1_home_or_not;
        string line2, team_2, team_2_score_string, team_2_home_or_not;
        int team_1_score, team_2_score, team_1_han, team_2_han;

        if (!getline(fin, line1)) {
            break;
        }

        if (!getline(fin, line2)) {
            break;
        } else {
            stringstream line1_stream(line1);
            getline(line1_stream, team_1, ',');
            getline(line1_stream, team_1_score_string, ',');
            team_1_score = stoi(team_1_score_string);
            getline(line1_stream, team_1_home_or_not, ',');
            team_1_han = stoi(team_1_home_or_not);

            stringstream line2_stream(line2);
            getline(line2_stream, team_2, ',');
            getline(line2_stream, team_2_score_string, ',');
            team_2_score = stoi(team_2_score_string);
            getline(line2_stream, team_2_home_or_not, ',');
            team_2_han = stoi(team_2_home_or_not);
        }

        auto team_1_iter = find(all_teams.begin(), all_teams.end(), team_1);
        auto team_2_iter = find(all_teams.begin(), all_teams.end(), team_2);

        if ((team_1_iter == all_teams.end()) || (team_2_iter == all_teams.end())) {
            continue;
        } else {
            // auto p_1 = (1 / (1 + pow(2.718281828459, (c*(team_1_score - team_2_score)))));
            auto p_1 = (1 / (1 + exp(c*(team_1_score - team_2_score))));
            auto p_2 = 1 - p_1;

            int team_1_ndx = team_1_iter - all_teams.begin();
            int team_2_ndx = team_2_iter - all_teams.begin();
            float home_court_adv_value_team_1;
            float home_court_adv_value_team_2;

            if (team_1_han == 1) {
                home_court_adv_value_team_1 = 0.967185762;
            } else if (team_1_han == -1) {
                home_court_adv_value_team_1 = 1.060400445;
            }
            else {
                home_court_adv_value_team_1 = 1;
            }

            if (team_2_han == 1) {
                home_court_adv_value_team_2 = 0.967185762;
            } else if (team_2_han == -1) {
                home_court_adv_value_team_2 = 1.060400445;
            }
            else {
                home_court_adv_value_team_2 = 1;
            }

            if (team_1_score > team_2_score) {

                auto new_team_1_score = all_scores[team_1_ndx] + (home_court_adv_value_team_1*k*(1 - p_1)); // this is BASICALLY y right?
                auto new_team_2_score = all_scores[team_2_ndx] - (home_court_adv_value_team_2* k*p_2); // this is basically y

                // all_scores[team_1_ndx] += k*(1 - p_1);
                // all_scores[team_2_ndx] -= k*p_2;

                auto new_elo_depend_mov = (pow((team_1_score - team_2_score + 3), 0.8)) / (7.5 + 0.006 * (abs(all_scores[team_1_ndx] - all_scores[team_2_ndx])));

                all_scores[team_1_ndx] = all_scores[team_1_ndx] + new_elo_depend_mov * abs(new_team_1_score - all_scores[team_1_ndx]);
                all_scores[team_2_ndx] = all_scores[team_2_ndx] - new_elo_depend_mov * abs(new_team_2_score - all_scores[team_2_ndx]);
                // z = x +- MOV(|y-x|)

                // all_scores[team_1_ndx] *= new_elo_depend_mov;
                // all_scores[team_2_ndx] *= new_elo_depend_mov;
            } else {
                auto new_team_2_score = all_scores[team_2_ndx] + (home_court_adv_value_team_2*k*(1 - p_2));
                auto new_team_1_score = all_scores[team_1_ndx] + (home_court_adv_value_team_1*k*p_1);
                

                // all_scores[team_2_ndx] += k*(1 - p_2);
                // all_scores[team_1_ndx] -= k*p_1;

                auto new_elo_depend_mov = (pow((team_2_score - team_1_score + 3), 0.8)) / (7.5 + 0.006 * (abs(all_scores[team_1_ndx] - all_scores[team_2_ndx])));
                all_scores[team_1_ndx] = all_scores[team_1_ndx] - new_elo_depend_mov * abs(new_team_1_score - all_scores[team_1_ndx]);
                all_scores[team_2_ndx] = all_scores[team_2_ndx] + new_elo_depend_mov * abs(new_team_2_score - all_scores[team_2_ndx]);

                // all_scores[team_1_ndx] *= new_elo_depend_mov;
                // all_scores[team_2_ndx] *= new_elo_depend_mov;
            }
        }
    }
    for (int j = 0; j < num_teams; j++) {
        cout << all_scores[j] << '\n';
    }
    return 0;
}