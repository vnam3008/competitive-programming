import sublime
import sublime_plugin
import datetime

# ==========================================
# TEMPLATE 1: Dành cho Cpp
# ==========================================
class InsertCppTemplateCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        current_time = datetime.datetime.now().strftime("%d.%m.%Y %H:%M:%S")
        template = """/*
    created: {}
    author: Tran Van Nam
    Da Nang University of Science and Technology - Viet Nam
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    $0
    
    return 0^0;
}}
""".format(current_time)
        self.view.run_command("insert_snippet", {"contents": template})


# ==========================================
# TEMPLATE 2: Dành cho Codeforces
# ==========================================
class InsertCodeforcesTemplateCommand(sublime_plugin.TextCommand):
    def run(self, edit):
        current_time = datetime.datetime.now().strftime("%d.%m.%Y %H:%M:%S")
        
        # Một template đơn giản hơn, rất hợp để hướng dẫn cho người mới học
        template = """/*
    created: {}
    author: Tran Van Nam
    Da Nang University of Science and Technology - Viet Nam
*/
#include <bits/stdc++.h>
using namespace std;

const int N           = 2e5  + 10;
const int MOD         = 1e9  + 7;
const int INF         = 1e9  + 10;
const long long INFLL = 1e18 + 10;

void solve(int test_case){{
    $0
}}

signed main(){{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int Test; cin >> Test; cin.ignore();
    for (int TestCase = 1; TestCase <= Test; TestCase++) solve(TestCase);
    
    return 0^0;
}}
""".format(current_time)
        self.view.run_command("insert_snippet", {"contents": template})