import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    customers.rename(columns={'name':'customers'}, inplace=True)
    return customers[~customers["id"].isin(orders["customerId"])][['customers']]