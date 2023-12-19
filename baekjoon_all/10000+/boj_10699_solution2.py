# Solve 2022-05-21
# Update 2023-12-19

import datetime

utc_time = datetime.datetime.utcnow()
kst_time = utc_time + datetime.timedelta(hours=9)
print(str(kst_time)[:10])
