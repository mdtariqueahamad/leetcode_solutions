import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    cnt = employee['managerId'].value_counts()
    x = cnt[cnt>=5].index
    return employee[employee['id'].isin(x)][['name']]
