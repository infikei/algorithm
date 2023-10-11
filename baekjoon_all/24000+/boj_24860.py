# Solve 2022-06-02
# Update 2023-10-11

# 그림을 보고 이해하기
# 위 그림 : V_kappa에서 하나, J_kappa에서 하나, V에서 하나, D에서 하나, J에서 하나 선택
# 아래 그림 : V_lambda에서 하나, J_lambda에서 하나, V에서 하나, D에서 하나, J에서 하나 선택

vk, jk = map(int, input().split())
vl, jl = map(int, input().split())
vh, dh, jh = map(int, input().split())

print((vk * jk + vl * jl) * vh * dh * jh)
