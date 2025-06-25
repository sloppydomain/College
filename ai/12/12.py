education_levels = ["high_school", "bachelor", "master", "phd"]
salary_categories = ["50k-", "50k-100k", "100k+"]

career_knowledge_base = [
    {
        "name": "Software Engineer",
        "minimum_education": "bachelor",
        "salary_category": "100k+",
        "interests": ["technology", "problem-solving"],
        "skills": ["programming", "analytical thinking"],
        "work_preference": ["remote", "office"]
    },
    {
        "name": "Data Scientist",
        "minimum_education": "master",
        "salary_category": "100k+",
        "interests": ["data analysis", "machine learning", "problem-solving"],
        "skills": ["programming", "statistics", "analytical thinking"],
        "work_preference": ["remote", "office"]
    },
    {
        "name": "Graphic Designer",
        "minimum_education": "bachelor",
        "salary_category": "50k-100k",
        "interests": ["arts", "creativity"],
        "skills": ["creativity", "communication"],
        "work_preference": ["remote", "office"]
    },
    {
        "name": "Field Engineer",
        "minimum_education": "bachelor",
        "salary_category": "50k-100k",
        "interests": ["technology", "problem-solving"],
        "skills": ["analytical thinking", "project management"],
        "work_preference": ["field"]
    },
    {
        "name": "High School Teacher",
        "minimum_education": "bachelor",
        "salary_category": "50k-",
        "interests": ["education", "arts"],
        "skills": ["communication", "creativity"],
        "work_preference": ["office"]
    }
]

def get_user_input():
    """Collect user preferences through CLI"""
    print("Welcome to the Career Guidance Expert System!")
    print("Please answer the following questions to get career recommendations.\n")
    print("Educational Background:")
    for i, level in enumerate(education_levels):
        print(f"{i+1}. {level.capitalize()}")
    education = int(input("Enter the number corresponding to your highest education level: "))
    user_education = education_levels[education-1]
    print("\nSalary Expectation:")
    for i, category in enumerate(salary_categories):
        print(f"{i+1}. {category}")
    salary = int(input("Enter the number corresponding to your expected salary: "))
    user_salary = salary_categories[salary-1]
    print("\nInterests (Choose all that apply):")
    interests = ["technology", "healthcare", "arts", "education", 
                "business", "data analysis", "machine learning", "problem-solving"]
    for i, interest in enumerate(interests):
        print(f"{i+1}. {interest.capitalize()}")
    selected = input("Enter numbers separated by commas: ").split(',')
    user_interests = [interests[int(i.strip())-1] for i in selected]
    print("\nSkills (Choose all that apply):")
    skills = ["programming", "communication", "project management", 
             "analytical thinking", "statistics", "creativity"]
    for i, skill in enumerate(skills):
        print(f"{i+1}. {skill.capitalize()}")
    selected = input("Enter numbers separated by commas: ").split(',')
    user_skills = [skills[int(i.strip())-1] for i in selected]
    print("\nWork Environment Preferences:")
    work_options = ["remote", "office", "field"]
    for i, option in enumerate(work_options):
        print(f"{i+1}. {option.capitalize()}")
    selected = input("Enter numbers separated by commas: ").split(',')
    user_work_pref = [work_options[int(i.strip())-1] for i in selected]
    return {
        "education": user_education,
        "salary": user_salary,
        "interests": user_interests,
        "skills": user_skills,
        "work_preference": user_work_pref
    }

def recommend_careers(user_data):
    """Match user profile with career database"""
    recommendations = []
    edu_idx = education_levels.index(user_data["education"])
    sal_idx = salary_categories.index(user_data["salary"])
    for career in career_knowledge_base:
        career_edu_idx = education_levels.index(career["minimum_education"])
        if edu_idx < career_edu_idx:
            continue  
        career_sal_idx = salary_categories.index(career["salary_category"])
        if career_sal_idx < sal_idx:
            continue  
        score = 0
        score += len(set(user_data["interests"]) & set(career["interests"]))
        score += len(set(user_data["skills"]) & set(career["skills"]))
        score += len(set(user_data["work_preference"]) & set(career["work_preference"]))
        recommendations.append((career["name"], score))
    recommendations.sort(key=lambda x: x[1], reverse=True)
    return recommendations

def display_results(recommendations):
    """Show recommendations to user"""
    if not recommendations:
        print("\nNo careers match your profile. Consider expanding your preferences.")
        return
    print("\nTop Career Recommendations:")
    max_score = recommendations[0][1]
    top_careers = [career for career, score in recommendations if score == max_score]
    for career in top_careers:
        print(f"- {career}")
    if len(recommendations) > len(top_careers):
        print("\nOther Potential Options:")
        for career, score in recommendations[len(top_careers):]:
            if score > 0:
                print(f"- {career} (Match Score: {score})")

if __name__ == "__main__":
    user_profile = get_user_input()
    career_matches = recommend_careers(user_profile)
    display_results(career_matches)

'''
IN/OUT:

Welcome to the Career Guidance Expert System!
Please answer the following questions to get career recommendations.

Educational Background:
1. High_school
2. Bachelor
3. Master
4. Phd
Enter the number corresponding to your highest education level: 2

Salary Expectation:
1. 50k-
2. 50k-100k
3. 100k+
Enter the number corresponding to your expected salary: 3

Interests (Choose all that apply):
1. Technology
2. Healthcare
3. Arts
4. Education
5. Business
6. Data analysis
7. Machine learning
8. Problem-solving
Enter numbers separated by commas: 8

Skills (Choose all that apply):
1. Programming
2. Communication
3. Project management
4. Analytical thinking
5. Statistics
6. Creativity
Enter numbers separated by commas: 1

Work Environment Preferences:
1. Remote
2. Office
3. Field
Enter numbers separated by commas: 2

Top Career Recommendations:
- Software Engineer
'''