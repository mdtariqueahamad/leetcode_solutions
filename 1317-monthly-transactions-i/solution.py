import pandas as pd

def monthly_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    transactions['trans_date'] = pd.to_datetime(transactions['trans_date'])
    transactions['month'] = transactions['trans_date'].dt.strftime('%Y-%m')

    transactions['approved'] = (transactions['state'] == 'approved').astype(int)
    transactions['approved_total_amount'] = transactions['amount'] * transactions['approved'] 

    return transactions.groupby(['month', 'country'] , dropna = False).agg(
        trans_count = ('id', 'count'),
        approved_count = ('approved', 'sum'),
        trans_total_amount = ('amount', 'sum'),
        approved_total_amount = ('approved_total_amount', 'sum')
    ).reset_index()
